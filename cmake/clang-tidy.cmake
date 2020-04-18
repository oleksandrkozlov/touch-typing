find_program(CLANG_TIDY_PATH clang-tidy)

if (NOT CLANG_TIDY_PATH)
    message(FATAL_ERROR "No program 'clang-tidy' found")
endif ()

find_program(RUN_CLANG_TIDY_PATH run-clang-tidy.py HINTS /usr/share/clang /usr/lib/*/share/clang/)

if (NOT RUN_CLANG_TIDY_PATH)
    message(FATAL_ERROR "No program 'run-clang-tidy.py' found")
endif ()

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
list(FILTER SOURCE_FILES EXCLUDE REGEX ${CMAKE_BINARY_DIR})

add_custom_target(
    clang-tidy
    COMMAND
        ${Python3_EXECUTABLE} ${RUN_CLANG_TIDY_PATH} -quiet -header-filter=.* -p
        ${CMAKE_BINARY_DIR} -j `nproc` ${SOURCE_FILES} >
        ${CMAKE_BINARY_DIR}/clang-tidy.txt
    COMMENT "Analyzing code by 'clang-tidy'"
)
