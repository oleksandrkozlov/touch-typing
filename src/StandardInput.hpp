#ifndef TOUCH_TYPING_STANDARD_INPUT_HPP
#define TOUCH_TYPING_STANDARD_INPUT_HPP

#include "Input.hpp"

namespace touch_typing {

class StandardInput : public Input {
private:
    auto readSymbol() -> int override;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_STANDARD_INPUT_HPP
