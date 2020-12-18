#ifndef TOUCH_TYPING_OUTPUT_HPP
#define TOUCH_TYPING_OUTPUT_HPP

#include "OutputResult.hpp"

#include <string>

namespace touch_typing {

class Output {
protected:
    Output() = default;
    Output(Output&& other) = default;
    Output(const Output& other) = default;

    auto operator=(Output&& other) -> Output& = default;
    auto operator=(const Output& other) -> Output& = default;

public:
    virtual ~Output() = default;

    virtual auto onGotInputText(
        [[maybe_unused]] const std::string& inputText) -> void
    {
    }

    virtual auto onGotOutputResult(
        [[maybe_unused]] OutputResult outputResult) -> void
    {
    }
};

} // namespace touch_typing

#endif // TOUCH_TYPING_OUTPUT_HPP
