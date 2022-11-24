module;

#define FMT_HEADER_ONLY
#include <fmt/core.h>

export module touch_typing:TextFile;

import <filesystem>;
import <fstream>;
import <iterator>;
import <stdexcept>;
import <string>;

export namespace touch_typing {

class TextFile {
public:
    explicit TextFile(const std::filesystem::path& filename)
    {
        auto fileStream = std::ifstream{filename};

        if (!fileStream.is_open()) {
            throw std::invalid_argument{
                fmt::format("Cannot open '{}'.", filename.string())};
        }

        m_text = std::string{
            (std::istreambuf_iterator<char>(fileStream)),
            std::istreambuf_iterator<char>()};
    }

    [[nodiscard]] auto asString() const noexcept -> const std::string&
    {
        return m_text;
    }

private:
    std::string m_text;
};

} // namespace touch_typing
