#include "Account.hpp"

#include <utility>

namespace touch_typing {

// cppcheck-suppress passedByValue
Account::Account(std::string username) noexcept
    : m_username{std::move(username)}
{
}

auto Account::getUsername() const noexcept -> const std::string&
{
    return m_username;
}

} // namespace touch_typing
