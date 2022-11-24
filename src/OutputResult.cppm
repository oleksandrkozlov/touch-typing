export module touch_typing:OutputResult;

export namespace touch_typing {

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
