#include "Interactor.hpp"

#include "Output.hpp"
#include "OutputResult.hpp"
#include "TextStorage.hpp"

namespace touch_typing {

Interactor::Interactor(
    const TextStorage& textStorage,
    Output& output) noexcept
    : m_textStorage{textStorage}
    , m_output{output}
    , m_inputText{m_textStorage.get().getText()}
{
    m_output.get().onGotInputText(m_inputText);
}

auto Interactor::enterSymbol(const int enteredSymbol) -> bool
{
    if (m_inputTextSize == m_position)
        return false;

    const auto expectedSymbol = static_cast<int>(
        static_cast<unsigned char>(m_inputText.at(m_position)));

    auto answer = OutputResult::Answer::Wrong;
    const auto backspace = 127;

    if (enteredSymbol == backspace) {
        if (m_position)
            --m_position;
        answer = OutputResult::Answer::Backspace;
    } else if (expectedSymbol == enteredSymbol) {
        ++m_position;
        answer = OutputResult::Answer::Correct;
    } else {
        ++m_position;
    }

    m_output.get().onGotOutputResult(
        OutputResult{expectedSymbol, enteredSymbol, answer});

    return m_inputTextSize != m_position;
    }

} // namespace touch_typing
