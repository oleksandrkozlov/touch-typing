find_program(IWYU_PROGRAM include-what-you-use)

if(NOT IWYU_PROGRAM)
    message(FATAL_ERROR "No program 'include-what-you-use' found")
endif()

if(RUN_IWYU_ON_BUILD)
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE
        "${IWYU_PROGRAM};-Xiwyu;--mapping_file=${CMAKE_SOURCE_DIR}/.iwyu")
endif()

find_package(Python3 COMPONENTS Interpreter REQUIRED)

find_program(IWYU_TOOL_PROGRAM iwyu_tool.py)

if(NOT IWYU_TOOL_PROGRAM)
    message(FATAL_ERROR "No program 'iwyu_tool.py' found")
endif()

add_custom_target(
    iwyu
    COMMAND
        ${Python3_EXECUTABLE} ${IWYU_TOOL_PROGRAM} -o clang -p . -j `nproc`
        -- -Xiwyu --mapping_file=${CMAKE_SOURCE_DIR}/.iwyu | tee iwyu.txt
    COMMAND ! grep error: iwyu.txt > /dev/null 2>&1
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Analyzing code by 'iwyu'")
