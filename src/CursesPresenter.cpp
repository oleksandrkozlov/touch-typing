#include "CursesPresenter.hpp"

#include <curses.h>

#include <cstdint>
#include <iterator>

namespace touch_typing {
namespace {

constexpr std::int16_t correctColor = 1;
constexpr std::int16_t wrongColor = 2;

} // namespace

CursesPresenter::CursesPresenter() noexcept
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

CursesPresenter::~CursesPresenter() noexcept
{
    endwin();
}

auto CursesPresenter::onGotInputText(const std::string& inputText) -> void
{
    m_inputText = inputText;
    printw("%s", m_inputText.c_str());
    refresh();
}

auto CursesPresenter::onGotOutputResult(OutputResult outputResult) -> void
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

} // namespace touch_typing
