add_library(
    touchtyping STATIC StandardPresenter.cpp Interactor.cpp Controller.cpp
                       TextStorage.cpp CursesPresenter.cpp)

add_executable(touch_typing TouchTyping.cpp)

target_link_libraries(touch_typing PRIVATE touchtyping curses)

target_include_directories(touchtyping PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
