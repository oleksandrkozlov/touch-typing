#ifndef TOUCH_TYPING_ERROR_HPP
#define TOUCH_TYPING_ERROR_HPP

#include <stdexcept>

namespace touch_typing {

class Error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class InvalidArgument : public Error {
    using Error::Error;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_ERROR_HPP
