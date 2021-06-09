add_library(
    touchtyping STATIC
    Account.cpp
    Controller.cpp
    CursesPresenter.cpp
    Interactor.cpp
    StandardPresenter.cpp
    TextFile.cpp
    TextStorage.cpp
    User.cpp
)

target_link_libraries(touchtyping PRIVATE fmt::fmt PkgConfig::ncurses Boost::serialization)

add_executable(touch_typing TouchTypingMain.cpp)

target_link_libraries(touch_typing PRIVATE touchtyping)

target_include_directories(touchtyping PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(touch_typing PRIVATE docopt spdlog::spdlog)

target_compile_definitions(
    touch_typing PRIVATE TOUCH_TYPING_DATA_DIR="${CMAKE_INSTALL_FULL_DATADIR}/touch_typing"
)

install(TARGETS touch_typing DESTINATION ${CMAKE_INSTALL_BINDIR})
