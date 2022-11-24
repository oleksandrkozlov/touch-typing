cmake_minimum_required(VERSION 3.16)

project(touch_typing VERSION 0.1.0 LANGUAGES CXX)

list(PREPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

include(flags)
include(packages)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
    include(options)
    include(ccache)
    include(cmake-format)
    include(clang-format)
    include(clang-tidy)
    include(cppcheck)
    include(sanitizers)
    include(iwyu)
    include(kcov)
    add_subdirectory(docs)
endif()

add_subdirectory(src)
add_subdirectory(data)

include(FeatureSummary)
feature_summary(WHAT ALL)
