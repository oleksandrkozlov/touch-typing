#include "User.hpp"

#include <utility>

// cppcheck-suppress passedByValue
User::User(std::string username) noexcept
    : m_username{std::move(username)}
{
}

auto User::getUsername() noexcept -> const std::string&
{
    return m_username;
}
