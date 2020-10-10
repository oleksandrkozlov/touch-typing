find_program(CLANG_TIDY_PROGRAM clang-tidy)

if(NOT CLANG_TIDY_PROGRAM)
    message(FATAL_ERROR "No program 'clang-tidy' found")
endif()

if(RUN_CLANG_TIDY_ON_BUILD)
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_PROGRAM})
endif()

find_package(Python3 3.8 COMPONENTS Interpreter REQUIRED)

find_program(
    RUN_CLANG_TIDY_PROGRAM run-clang-tidy.py HINTS /usr/share/clang /usr/lib/*/share/clang/
)

if(NOT RUN_CLANG_TIDY_PROGRAM)
    message(FATAL_ERROR "No program 'run-clang-tidy.py' found")
endif()

add_custom_target(
    clang-tidy
    COMMAND ${Python3_EXECUTABLE} ${RUN_CLANG_TIDY_PROGRAM} -quiet -header-filter=.* -p . -j `nproc`
            | tee clang-tidy.txt
    COMMAND ! grep warning clang-tidy.txt > /dev/null 2>&1
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Analyzing code by 'clang-tidy'"
)
