#include "Interactor.hpp"

#include "Output.hpp"
#include "OutputResult.hpp"
#include "StandartInput.hpp"

#include <iostream>

namespace touch_typing {

Interactor::Interactor(Output& output) noexcept
    : m_input{std::make_unique<touch_typing::StandartInput>()}
    , m_output{output}
{
    using namespace std::string_literals;
    const auto inputText = "Hello, World!"s;
    m_output.get().onGotInputText(inputText);
    auto inputTextSize = std::size(inputText);
    decltype(inputTextSize) position = 0;

    while (inputTextSize != position) {
        const auto enteredSymbol = m_input->readSymbol();
        const decltype(enteredSymbol) carriageReturnSymbol = 10;

        if (enteredSymbol == carriageReturnSymbol)
            continue;

        const auto expectedSymbol =
            static_cast<decltype(enteredSymbol)>(inputText.at(position));

        auto answer = OutputResult::Answer::Wrong;

        if (expectedSymbol == enteredSymbol) {
            ++position;
            answer = OutputResult::Answer::Correct;
        }

        m_output.get().onGotOutputResult(
            OutputResult{expectedSymbol, enteredSymbol, answer});
    }
}

} // namespace touch_typing
