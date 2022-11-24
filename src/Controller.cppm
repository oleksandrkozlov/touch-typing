module;

#include <curses.h>

export module touch_typing:Controller;

import :Interactor;
import <cstdio>;
import <functional>;

export namespace touch_typing {

class Controller {
public:
    explicit Controller(Interactor& interactor) noexcept
        : m_interactor{interactor}
    {
        initscr();
    }

    Controller(Controller&& other) = default;
    Controller(const Controller& other) = delete;

    auto operator=(Controller&& other) -> Controller& = default;
    auto operator=(const Controller& other) -> Controller& = delete;

    ~Controller() noexcept
    {
        endwin();
    }

    auto readSymbols() -> void
    {
        while (m_interactor.get().enterSymbol(getchar()))
            ;
    }

private:
    std::reference_wrapper<Interactor> m_interactor;
};

} // namespace touch_typing
