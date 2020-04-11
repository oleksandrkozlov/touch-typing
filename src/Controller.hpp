#ifndef TOUCH_TYPING_CONTROLLER_HPP
#define TOUCH_TYPING_CONTROLLER_HPP

#include "Input.hpp"

#include <functional>
#include <string_view>

namespace touch_typing {

class Controller {
public:
    explicit Controller(Input& input) noexcept;

    auto enterSymbols(std::string_view enterSymbols) -> void;

private:
    std::reference_wrapper<Input> m_input;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_CONTROLLER_HPP
