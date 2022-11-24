export module touch_typing:Interactor;

import :Output;
import :OutputResult;
import :TextStorage;
import <cstddef>;
import <functional>;
import <iterator>;
import <string>;

export namespace touch_typing {

class Interactor {
public:
    Interactor(const TextStorage& textStorage, Output& output)
        : m_textStorage{textStorage}
        , m_output{output}
        , m_inputText{m_textStorage.get().getText()}
    {
        m_output.get().onGotInputText(m_inputText);
    }

    auto enterSymbol(const int enteredSymbol) -> bool
    {
        if (m_inputTextSize == m_position)
            return false;

        const auto expectedSymbol = static_cast<int>(
            static_cast<unsigned char>(m_inputText.at(m_position)));

        auto answer = OutputResult::Answer::Wrong;
        const auto backspace = 127;

        if (enteredSymbol == backspace) {
            if (m_position)
                --m_position;
            answer = OutputResult::Answer::Backspace;
        } else if (expectedSymbol == enteredSymbol) {
            ++m_position;
            answer = OutputResult::Answer::Correct;
        } else {
            ++m_position;
        }

        m_output.get().onGotOutputResult(
            OutputResult{expectedSymbol, enteredSymbol, answer});

        return m_inputTextSize != m_position;
    }

private:
    std::reference_wrapper<const TextStorage> m_textStorage;
    std::reference_wrapper<Output> m_output;
    std::string m_inputText;
    std::size_t m_inputTextSize = std::size(m_inputText);
    std::size_t m_position = 0;
};

} // namespace touch_typing
