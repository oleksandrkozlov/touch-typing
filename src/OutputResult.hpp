#ifndef TOUCH_TYPING_OUTPUT_RESULT_HPP
#define TOUCH_TYPING_OUTPUT_RESULT_HPP

namespace touch_typing {

struct OutputResult {
    enum class Answer {
        Wrong,
        Correct,
        Backspace,
    };

    int expectedSymbol;
    int enteredSymbol;
    Answer answer;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_OUTPUT_RESULT_HPP
