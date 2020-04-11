#include "StandardInput.hpp"

#include <cstdio>

namespace touch_typing {

auto StandardInput::readSymbol() -> int
{
    return std::getchar();
}

} // namespace touch_typing
