find_program(CLANG_TIDY_PROGRAM clang-tidy)

if(NOT CLANG_TIDY_PROGRAM)
    message(FATAL_ERROR "No program 'clang-tidy' found")
endif()

find_package(Python3 COMPONENTS Interpreter REQUIRED)

find_program(RUN_CLANG_TIDY_PROGRAM run-clang-tidy.py
             HINTS /usr/share/clang /usr/lib/*/share/clang/)

if(NOT RUN_CLANG_TIDY_PROGRAM)
    message(FATAL_ERROR "No program 'run-clang-tidy.py' found")
endif()

add_custom_target(
    clang-tidy
    COMMAND
        ${Python3_EXECUTABLE} ${RUN_CLANG_TIDY_PROGRAM} -quiet
        -header-filter=.* -p ${CMAKE_BINARY_DIR} -j `nproc` >
        ${CMAKE_BINARY_DIR}/clang-tidy.txt
    COMMENT "Analyzing code by 'clang-tidy'")
