cmake_minimum_required(VERSION 3.10)

project(touch_typing VERSION 0.1.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wshadow -Wpedantic)

enable_testing()

option(RUN_IWYU_ON_BUILD "Run 'iwyu' during the build" OFF)
option(RUN_CLANG_TIDY_ON_BUILD "Run 'clang-tidy' during the build" OFF)

include(cppcheck)
include(clang-tidy)
include(clang-format)
include(cmake-format)
include(kcov)
include(iwyu)

add_subdirectory(src)
add_subdirectory(tests)
