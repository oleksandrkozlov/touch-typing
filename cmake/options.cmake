function(set_option name description value)
    option(name description value)
    message(STATUS "${description}: ${value}")
endfunction()

set_option(RUN_IWYU_ON_BUILD "Run 'iwyu' during the build" OFF)
set_option(RUN_CLANG_TIDY_ON_BUILD "Run 'clang-tidy' during the build" OFF)
