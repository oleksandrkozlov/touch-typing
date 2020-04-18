#ifndef TOUCH_TYPING_CONTROLLER_HPP
#define TOUCH_TYPING_CONTROLLER_HPP

#include "Input.hpp"

#include <functional>
#include <string_view>

namespace touch_typing {

class Controller {
public:
    explicit Controller(Input& input) noexcept;
    Controller(Controller&& other) = default;
    Controller(const Controller& other) = delete;

    auto operator=(Controller&& other) -> Controller& = default;
    auto operator=(const Controller& other) -> Controller& = delete;

    ~Controller() noexcept;

    auto readSymbols() -> void;

private:
    std::reference_wrapper<Input> m_input;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_CONTROLLER_HPP
