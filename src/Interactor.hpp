#ifndef TOUCH_TYPING_INTERACTOR_HPP
#define TOUCH_TYPING_INTERACTOR_HPP

#include "Input.hpp"

#include <cstddef>
#include <functional>
#include <iterator>
#include <string>

namespace touch_typing {

class Output;
class TextStorage;

class Interactor : public Input {
public:
    explicit Interactor(
        const TextStorage& textStorage,
        Output& output) noexcept;

private:
    auto enterSymbol(int enteredSymbol) -> bool override;

    std::reference_wrapper<const TextStorage> m_textStorage;
    std::reference_wrapper<Output> m_output;
    std::string m_inputText;
    std::size_t m_inputTextSize = std::size(m_inputText);
    std::size_t m_position = 0;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_INTERACTOR_HPP
