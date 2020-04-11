#include "Controller.hpp"

namespace touch_typing {

Controller::Controller(Input& input) noexcept
    : m_input{input}
{
}

auto Controller::enterSymbols(const std::string_view enteredSymbols) -> void
{
    std::size_t pos = 0;

    while (m_input.get().enterSymbol(enteredSymbols.at(pos)))
        ++pos;
}

} // namespace touch_typing
