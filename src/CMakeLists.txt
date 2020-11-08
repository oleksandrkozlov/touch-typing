add_library(
    touchtyping STATIC StandardPresenter.cpp Interactor.cpp Controller.cpp TextStorage.cpp
                       CursesPresenter.cpp
)

add_executable(touch_typing TouchTyping.cpp)

target_link_libraries(touch_typing PRIVATE touchtyping PkgConfig::ncurses)

target_include_directories(touchtyping PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(touch_typing PRIVATE docopt)

install(TARGETS touch_typing DESTINATION ${CMAKE_INSTALL_BINDIR})
