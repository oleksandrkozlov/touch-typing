#include "CursesPresenter.hpp"

#include <curses.h>

#include <iterator>
#include <utility>

namespace touch_typing {
namespace {

const short CorrectColor = 1;
const short WrongColor = 2;

} // namespace

CursesPresenter::CursesPresenter() noexcept
{
    initscr();
    noecho();
    cbreak();
    start_color();
    use_default_colors();
    const short backgroundColor = -1;
    init_pair(CorrectColor, COLOR_GREEN, backgroundColor);
    init_pair(WrongColor, COLOR_RED, backgroundColor);
}

CursesPresenter::~CursesPresenter() noexcept
{
    endwin();
}

auto CursesPresenter::onGotInputText(std::string inputText) -> void
{
    m_inputText = std::move(inputText);
    printw("%s", m_inputText.c_str());
    refresh();
}

auto CursesPresenter::onGotOutputResult(OutputResult outputResult) -> void
{
    if (outputResult.answer == OutputResult::Answer::Backspace) {
        if (!std::empty(m_enteredText))
            m_enteredText.pop_back();
    } else {
        m_enteredText.push_back(std::move(outputResult));
    }

    clear();

    for (const auto& result : m_enteredText) {
        auto color = (result.answer == OutputResult::Answer::Correct)
            ? CorrectColor
            : WrongColor;
        addch(result.enteredSymbol | COLOR_PAIR(color));
    }

    printw("%s", m_inputText.substr(std::size(m_enteredText)).c_str());

    refresh();
}

} // namespace touch_typing
