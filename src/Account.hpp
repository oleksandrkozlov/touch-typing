#ifndef TOUCH_TYPING_ACCOUNT_HPP
#define TOUCH_TYPING_ACCOUNT_HPP

#include <boost/serialization/access.hpp> // IWYU pragma: keep

#include <string>

namespace touch_typing {

class Account {
    friend class boost::serialization::access;

public:
    Account() = default;

    explicit Account(std::string username) noexcept;

    [[nodiscard]] auto getUsername() const noexcept -> const std::string&;

private:
    template<typename Archive>
    void serialize(
        Archive& archive,
        [[maybe_unused]] const unsigned int version)
    {
        archive& m_username;
    }

    std::string m_username{};
};

inline auto operator==(const Account& lhs, const Account& rhs) noexcept
    -> bool
{
    return lhs.getUsername() == rhs.getUsername();
}

} // namespace touch_typing

#endif // TOUCH_TYPING_ACCOUNT_HPP
