include(CTest)
find_package(GTest REQUIRED)
add_executable(touch_typing_tests TouchTypingTests.cpp)
target_link_libraries(touch_typing_tests PRIVATE GTest::Main touchtyping)

add_test(NAME touch_typing_tests COMMAND touch_typing_tests
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

add_coverage(NAME kcov EXECUTABLE touch_typing_tests)
