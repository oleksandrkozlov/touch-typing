find_program(CPPCHECK_PROGRAM cppcheck)

if(NOT CPPCHECK_PROGRAM)
    message(FATAL_ERROR "No program 'cppcheck' found")
endif()

add_custom_target(
    cppcheck
    COMMAND
        ${CPPCHECK_PROGRAM} --quiet --enable=all --project=compile_commands.json --xml
        --xml-version=2 --suppress=missingInclude --suppress=syntaxError
        --suppress=unmatchedSuppression --inline-suppr -i . ${CMAKE_SOURCE_DIR} 2> cppcheck.xml
    COMMAND cat cppcheck.xml
    COMMAND ! grep '\\<error ' cppcheck.xml > /dev/null 2>&1
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Analyzing code by 'cppcheck'"
)
