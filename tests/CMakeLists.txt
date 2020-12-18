include(CTest)
find_package(GTest 1.10 REQUIRED)
add_executable(
    touch_typing_tests TouchTypingTests.cpp TextFileTests.cpp TempFile.cpp BinaryStorageTests.cpp
                       AccountsTests.cpp
)
target_link_libraries(
    touch_typing_tests PRIVATE GTest::Main fmt::fmt Boost::serialization touchtyping
)

add_test(NAME touch_typing_tests COMMAND touch_typing_tests
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

add_coverage(NAME kcov EXECUTABLE touch_typing_tests)
