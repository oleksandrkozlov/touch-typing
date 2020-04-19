find_program(IWYU_PROGRAM include-what-you-use)

if(NOT IWYU_PROGRAM)
    message(FATAL_ERROR "No program 'include-what-you-use' found")
endif()

set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE "${IWYU_PROGRAM};-Xiwyu;--mapping_file=${CMAKE_SOURCE_DIR}/.iwyu")

find_package(
    Python3
    COMPONENTS Interpreter
    REQUIRED
)

find_program(IWYU_TOOL_PATH iwyu_tool.py)

if(NOT IWYU_TOOL_PATH)
    message(FATAL_ERROR "No program 'iwyu_tool.py' found")
endif()


add_custom_target(
    iwyu
    COMMAND
        ${Python3_EXECUTABLE} ${IWYU_TOOL_PATH} -p ${CMAKE_BINARY_DIR}
        -j `nproc` -- -Xiwyu --mapping_file=${CMAKE_SOURCE_DIR}/.iwyu >
        ${CMAKE_BINARY_DIR}/iwyu.txt
    COMMENT "Analyzing code by 'iwyu'"
)
