add_library(touchtyping STATIC StandardInput.cpp StandardOutput.cpp Interactor.cpp)

add_executable(touch_typing TouchTyping.cpp)

target_link_libraries(touch_typing PRIVATE touchtyping)
