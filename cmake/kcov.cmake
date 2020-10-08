find_program(KCOV_PROGRAM kcov)

if(NOT KCOV_PROGRAM)
    message(FATAL_ERROR "No program 'kcov' found")
endif()

function(add_coverage)
    cmake_parse_arguments(COVERAGE "" "NAME;EXECUTABLE" "" ${ARGN})
    add_custom_target(
        ${COVERAGE_NAME}
        COMMAND ${KCOV_PROGRAM} --include-pattern=/src ${CMAKE_BINARY_DIR}/${COVERAGE_NAME}
                ${COVERAGE_EXECUTABLE}
        DEPENDS ${COVERAGE_EXECUTABLE}
        COMMENT "Collecting code coverage by 'kcov'"
    )
endfunction()
