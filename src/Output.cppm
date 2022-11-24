export module touch_typing:Output;

import :OutputResult;
import <string>;

export namespace touch_typing {

class Output {
protected:
    Output() = default;
    Output(Output&& other) = default;
    Output(const Output& other) = default;

    auto operator=(Output&& other) -> Output& = default;
    auto operator=(const Output& other) -> Output& = default;

public:
    virtual ~Output() = default;

    virtual auto onGotInputText(const std::string& inputText) -> void = 0;

    virtual auto onGotOutputResult(OutputResult outputResult) -> void = 0;
};

} // namespace touch_typing
