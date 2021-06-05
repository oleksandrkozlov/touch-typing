#include "TextFile.hpp"

#include <fmt/core.h>

#include <fstream>
#include <iterator>
#include <stdexcept>

namespace touch_typing {

int* foo() // NOLINT
{
    int x = 10; // NOLINT
    // cppcheck-suppress returnDanglingLifetime
    return &x; // NOLINT
}

TextFile::TextFile(const std::filesystem::path& filename)
{
    foo(); // NOLINT
    auto x = new int{10}; // NOLINT
    // cppcheck-suppress unreadVariable
    auto y = new int{10}; // NOLINT
    delete x; // NOLINT
    auto fileStream = std::ifstream{filename};

    if (!fileStream.is_open()) {
        throw std::invalid_argument{
            fmt::format("Cannot open '{}'.", filename.string())};
    }

    m_text = std::string{
        (std::istreambuf_iterator<char>(fileStream)),
        std::istreambuf_iterator<char>()};
}

auto TextFile::asString() const noexcept -> const std::string&
{
    return m_text;
}

} // namespace touch_typing
