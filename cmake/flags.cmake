set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PREBUILT_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

add_compile_options(
    "$<$<CXX_COMPILER_ID:GNU>:-Wduplicated-branches;-Wduplicated-cond;-Wlogical-op;-Wuseless-cast>"
    -Wall
    -Wcast-align
    -Wconversion
    -Wdouble-promotion
    -Wextra
    -Wformat=2
    -Wmisleading-indentation
    -Wnon-virtual-dtor
    -Wnull-dereference
    -Wold-style-cast
    -Woverloaded-virtual
    -Wpedantic
    -Wshadow
    -Wunused
    -fmodules
    -stdlib=libc++
    -fprebuilt-module-path=${PREBUILT_MODULE_PATH}
)
