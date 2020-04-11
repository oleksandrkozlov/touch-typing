#include "StandardPresenter.hpp"

#include "OutputResult.hpp"

#include <iostream>

namespace touch_typing {

auto StandardPresenter::onGotInputText(const std::string& inputText) -> void
{
    std::cout << "Input: " << inputText << std::endl;
}

auto StandardPresenter::onGotOutputResult(
    const OutputResult outputResult) -> void
{
    std::cout << "'" << (char)outputResult.enteredSymbol << "'"
              << std::endl;
    switch (outputResult.answer) {
        case OutputResult::Answer::Correct:
            break;
        case OutputResult::Answer::Wrong:
            std::cout << "try again: '"
                      << static_cast<char>(outputResult.expectedSymbol)
                      << "'" << std::endl;
            break;
    }
}

} // namespace touch_typing
