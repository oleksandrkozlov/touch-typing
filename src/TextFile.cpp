#include "TextFile.hpp"

#include <fstream>
#include <iterator>
#include <stdexcept>

namespace touch_typing {

TextFile::TextFile(const std::filesystem::path& filename)
{
    auto fileStream = std::ifstream{filename};

    if (!fileStream.is_open())
        throw std::invalid_argument{"Cannot open " + filename.string()};

    m_text = std::string{
        (std::istreambuf_iterator<char>(fileStream)),
        std::istreambuf_iterator<char>()};
}

auto TextFile::asString() const noexcept -> const std::string&
{
    return m_text;
}

} // namespace touch_typing
