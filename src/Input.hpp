#ifndef TOUCH_TYPING_INPUT_HPP
#define TOUCH_TYPING_INPUT_HPP

namespace touch_typing {

class Input {
protected:
    Input() = default;
    Input(Input&& other) = default;
    Input(const Input& other) = default;

    auto operator=(Input&& other) -> Input& = default;
    auto operator=(const Input& other) -> Input& = default;

public:
    virtual ~Input() = default;

    virtual auto readSymbol() -> int = 0;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_INPUT_HPP
