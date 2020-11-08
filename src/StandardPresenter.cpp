#include "StandardPresenter.hpp"

#include "OutputResult.hpp"

#include <fmt/core.h>

namespace touch_typing {

auto StandardPresenter::onGotInputText(const std::string& inputText) -> void
{
    fmt::print("Input: {}\n", inputText);
}

auto StandardPresenter::onGotOutputResult(const OutputResult outputResult)
    -> void
{
    fmt::print("'{}'\n", static_cast<char>(outputResult.enteredSymbol));
    switch (outputResult.answer) {
        case OutputResult::Answer::Correct:
            break;
        case OutputResult::Answer::Wrong:
        case OutputResult::Answer::Backspace:
            fmt::print(
                "try again: '{}'\n",
                static_cast<char>(outputResult.expectedSymbol));
            break;
    }
}

} // namespace touch_typing
