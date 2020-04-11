#ifndef TOUCH_TYPING_INTERACTOR_HPP
#define TOUCH_TYPING_INTERACTOR_HPP

#include "Input.hpp"

#include <functional>

namespace touch_typing {

class Output;

class Interactor {
public:
    explicit Interactor(Output& output) noexcept;

private:
    std::unique_ptr<Input> m_input;
    std::reference_wrapper<Output> m_output;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_INTERACTOR_HPP
