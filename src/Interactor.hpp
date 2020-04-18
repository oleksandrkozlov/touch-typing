#ifndef TOUCH_TYPING_INTERACTOR_HPP
#define TOUCH_TYPING_INTERACTOR_HPP

#include "Input.hpp"

#include <functional>
#include <string>

namespace touch_typing {

class Output;

class Interactor : public Input {
public:
    explicit Interactor(Output& output) noexcept;

private:
    auto enterSymbol(int enteredSymbol) -> bool override;

    std::reference_wrapper<Output> m_output;
    std::string m_inputText = "Hello, World!";
    std::size_t m_inputTextSize = std::size(m_inputText);
    std::size_t m_position = 0;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_INTERACTOR_HPP
