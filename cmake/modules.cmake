function(add_module input output)
    file(MAKE_DIRECTORY ${PREBUILT_MODULE_PATH})
    add_custom_command(
        OUTPUT ${PREBUILT_MODULE_PATH}/${output} ${CMAKE_CURRENT_BINARY_DIR}/${output}.o
        COMMAND
            ${CMAKE_CXX_COMPILER} -std=c++20 -stdlib=libc++ -fmodules --precompile
            -fprebuilt-module-path=${PREBUILT_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/${input} -o
            ${PREBUILT_MODULE_PATH}/${output}
        COMMAND ${CMAKE_CXX_COMPILER} -c ${PREBUILT_MODULE_PATH}/${output} -o ${output}.o
        DEPENDS ${input}
        COMMENT "Precompiling the module ${input}"
    )
    add_custom_target(${output} DEPENDS ${PREBUILT_MODULE_PATH}/${output})
endfunction()
