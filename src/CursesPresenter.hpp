#ifndef TOUCH_TYPING_CURSES_PRESENTER_HPP
#define TOUCH_TYPING_CURSES_PRESENTER_HPP

#include "Output.hpp"
#include "OutputResult.hpp"

#include <deque>
#include <string>

namespace touch_typing {

class CursesPresenter : public Output {
public:
    CursesPresenter() noexcept;
    CursesPresenter(CursesPresenter&& other) = default;
    CursesPresenter(const CursesPresenter& other) = delete;

    auto operator=(CursesPresenter&& other) -> CursesPresenter& = default;
    auto operator=(const CursesPresenter& other)
        -> CursesPresenter& = delete;

    ~CursesPresenter() noexcept override;

private:
    auto onGotInputText(const std::string& inputText) -> void override;
    auto onGotOutputResult(OutputResult result) -> void override;

    std::deque<OutputResult> m_enteredText;
    std::string m_inputText;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_CURSES_PRESENTER_HPP
