module;

#include <curses.h>

export module touch_typing:CursesPresenter;

import :Output;
import :OutputResult;
import <cstdint>;
import <deque>;
import <deque>;
import <iterator>;
import <string>;
import <string>;

export namespace touch_typing {

class CursesPresenter : public Output {
public:
    CursesPresenter()
    {
        initscr();
        noecho();
        cbreak();
        start_color();
        use_default_colors();
        const std::int16_t backgroundColor = -1;
        init_pair(correctColor, COLOR_GREEN, backgroundColor);
        init_pair(wrongColor, COLOR_RED, backgroundColor);
    }

    CursesPresenter(CursesPresenter&& other) = default;
    CursesPresenter(const CursesPresenter& other) = delete;

    auto operator=(CursesPresenter&& other) -> CursesPresenter& = default;
    auto operator=(const CursesPresenter& other)
        -> CursesPresenter& = delete;

    ~CursesPresenter() noexcept override
    {
        endwin();
    }

private:
    auto onGotInputText(const std::string& inputText) -> void override
    {
        m_inputText = inputText;
        printw("%s", m_inputText.c_str());
        refresh();
    }

    auto onGotOutputResult(OutputResult outputResult) -> void override
    {
        if (outputResult.answer == OutputResult::Answer::Backspace) {
            if (!std::empty(m_enteredText))
                m_enteredText.pop_back();
        } else {
            m_enteredText.push_back(outputResult);
        }

        clear();

        for (const auto& result : m_enteredText) {
            auto color = (result.answer == OutputResult::Answer::Correct)
                ? correctColor
                : wrongColor;
            addch(
                static_cast<std::uint32_t>(result.enteredSymbol) |
                COLOR_PAIR(color));
        }

        printw("%s", m_inputText.substr(std::size(m_enteredText)).c_str());

        refresh();
    }

    static constexpr std::int16_t correctColor = 1;
    static constexpr std::int16_t wrongColor = 2;

    std::deque<OutputResult> m_enteredText;
    std::string m_inputText;
};

} // namespace touch_typing
