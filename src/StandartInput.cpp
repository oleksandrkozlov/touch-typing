#include "StandartInput.hpp"

#include <cstdio>

namespace touch_typing {

auto StandartInput::readSymbol() -> int
{
    return std::getchar();
}

} // namespace touch_typing
