add_library(
    touchtyping STATIC StandardPresenter.cpp Interactor.cpp Controller.cpp TextStorage.cpp
                       CursesPresenter.cpp TextFile.cpp
)

add_executable(touch_typing TouchTyping.cpp)

target_link_libraries(touch_typing PRIVATE touchtyping PkgConfig::ncurses)

target_include_directories(touchtyping PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(touch_typing PRIVATE docopt)
target_compile_definitions(
    touch_typing PRIVATE TOUCH_TYPING_DATA_DIR="${CMAKE_INSTALL_FULL_DATADIR}/touch_typing"
)

install(TARGETS touch_typing DESTINATION ${CMAKE_INSTALL_BINDIR})
