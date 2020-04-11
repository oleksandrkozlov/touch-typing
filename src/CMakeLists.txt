add_library(touchtyping STATIC StandardPresenter.cpp StandardInteractor.cpp Controller.cpp)

add_executable(touch_typing TouchTyping.cpp)

target_link_libraries(touch_typing PRIVATE touchtyping)
