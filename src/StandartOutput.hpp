#ifndef TOUCH_TYPING_STANDART_OUTPUT_HPP
#define TOUCH_TYPING_STANDART_OUTPUT_HPP

#include "Output.hpp"

namespace touch_typing {

class StandartOutput : public Output {
private:
    auto onGotInputText(const std::string& inputText) -> void override;
    auto onGotOutputResult(OutputResult result) -> void override;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_STANDART_OUTPUT_HPP
