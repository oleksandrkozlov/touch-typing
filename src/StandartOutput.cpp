#include "StandartOutput.hpp"

#include "OutputResult.hpp"

#include <iostream>

namespace touch_typing {

auto StandartOutput::onGotInputText(const std::string& inputText) -> void
{
    std::cout << "Input: " << inputText << std::endl;
}

auto StandartOutput::onGotOutputResult(const OutputResult outputResult)
    -> void
{
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
