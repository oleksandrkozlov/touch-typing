add_library(touchtyping STATIC StandartInput.cpp StandartOutput.cpp Interactor.cpp)

add_executable(touch_typing TouchTyping.cpp)

target_link_libraries(touch_typing PRIVATE touchtyping)
