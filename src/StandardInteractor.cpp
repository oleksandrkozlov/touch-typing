#include "StandardInteractor.hpp"

#include "Output.hpp"
#include "OutputResult.hpp"


namespace touch_typing {

StandardInteractor::StandardInteractor(Output& output) noexcept
    : m_output{output}
{
    m_output.get().onGotInputText(m_inputText);
}

auto StandardInteractor::enterSymbol(const int enteredSymbol) -> bool
{
    if (m_inputTextSize == m_position)
        return false;

    const auto expectedSymbol =
        static_cast<decltype(enteredSymbol)>(m_inputText.at(m_position));

    auto answer = OutputResult::Answer::Wrong;

    if (expectedSymbol == enteredSymbol) {
        ++m_position;
        answer = OutputResult::Answer::Correct;
    }

    m_output.get().onGotOutputResult(
        OutputResult{expectedSymbol, enteredSymbol, answer});

    if (m_inputTextSize == m_position)
        return false;
    return true;
}

} // namespace touch_typing
