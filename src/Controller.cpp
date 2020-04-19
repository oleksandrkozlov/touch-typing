#include "Controller.hpp"

#include "Input.hpp"

#include <curses.h>

namespace touch_typing {

Controller::Controller(Input& input) noexcept
    : m_input{input}
{
    initscr();
}

Controller::~Controller() noexcept
{
    endwin();
}

auto Controller::readSymbols() -> void
{
    while (m_input.get().enterSymbol(getch()))
        ;
}

} // namespace touch_typing
