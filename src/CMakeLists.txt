include(modules)

add_module(Output.cppm touch_typing-Output.pcm)
add_module(OutputResult.cppm touch_typing-OutputResult.pcm)
add_module(Controller.cppm touch_typing-Controller.pcm)
add_module(CursesPresenter.cppm touch_typing-CursesPresenter.pcm)
add_module(Interactor.cppm touch_typing-Interactor.pcm)
add_module(TextFile.cppm touch_typing-TextFile.pcm)
add_module(TextStorage.cppm touch_typing-TextStorage.pcm)
add_module(touch_typing.cppm touch_typing.pcm)

add_dependencies(touch_typing-CursesPresenter.pcm touch_typing-Output.pcm touch_typing-OutputResult.pcm)
add_dependencies(touch_typing-Interactor.pcm touch_typing-Output.pcm touch_typing-TextStorage.pcm)
add_dependencies(touch_typing-Output.pcm touch_typing-OutputResult.pcm)
add_dependencies(touch_typing-Controller.pcm touch_typing-Interactor.pcm)
add_dependencies(
    touch_typing.pcm
    touch_typing-Controller.pcm
    touch_typing-CursesPresenter.pcm
    touch_typing-Interactor.pcm
    touch_typing-Output.pcm
    touch_typing-OutputResult.pcm
    touch_typing-TextFile.pcm
    touch_typing-TextStorage.pcm
)

add_executable(touch_typing TouchTyping.cpp)
add_dependencies(touch_typing touch_typing.pcm)

target_link_libraries(touch_typing
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing-TextStorage.pcm.o
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing.pcm.o
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing-Controller.pcm.o
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing-CursesPresenter.pcm.o
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing-Interactor.pcm.o
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing-Output.pcm.o
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing-OutputResult.pcm.o
    ${CMAKE_CURRENT_BINARY_DIR}/touch_typing-TextFile.pcm.o
    -std=c++20 -fmodules -fprebuilt-module-path=. -stdlib=libc++ -lncurses)

install(TARGETS touch_typing DESTINATION ${CMAKE_INSTALL_BINDIR})
