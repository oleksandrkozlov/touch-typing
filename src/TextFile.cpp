#include "TextFile.hpp"

#include "Error.hpp"

#include <fmt/core.h>

#include <fstream>
#include <iterator>

namespace touch_typing {

TextFile::TextFile(const std::filesystem::path& filename)
{
    auto fileStream = std::ifstream{filename};

    if (!fileStream.is_open()) {
        throw InvalidArgument{
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
