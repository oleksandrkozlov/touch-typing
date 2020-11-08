cmake_minimum_required(VERSION 3.16)

project(touch_typing VERSION 0.1.0 LANGUAGES CXX)

list(PREPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

include(flags)
include(options)
include(packages)
include(GNUInstallDirs)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    include(cmake-format)
    include(clang-format)
    include(clang-tidy)
    include(cppcheck)
    include(iwyu)
    include(kcov)
    enable_testing()
    add_subdirectory(tests)
    add_subdirectory(docs)
endif()

add_subdirectory(src)
add_subdirectory(data)
