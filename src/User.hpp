#ifndef TOUCH_TYPING_USER_HPP
#define TOUCH_TYPING_USER_HPP

#include <string>

class User {
public:
    explicit User(std::string username) noexcept;

    auto getUsername() noexcept -> const std::string&;

private:
    std::string m_username{};
};

#endif // TOUCH_TYPING_USER_HPP
