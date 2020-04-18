find_program (CPPCHECK_PATH cppcheck)

if (NOT CPPCHECK_PATH)
    message (FATAL_ERROR "No program 'cppcheck' found")
endif ()

add_custom_target (
    cppcheck
    COMMAND
        ${CPPCHECK_PATH} --quiet --enable=all --project=${CMAKE_BINARY_DIR}/compile_commands.json
        --xml --xml-version=2 --suppress=unusedPrivateFunction --suppress=missingInclude
        --suppress=syntaxError --suppress=unmatchedSuppression --inline-suppr -i ${CMAKE_BINARY_DIR}
        ${CMAKE_SOURCE_DIR} 2> ${CMAKE_BINARY_DIR}/cppcheck.xml
    COMMENT "Analyzing code by 'cppcheck'"
)
