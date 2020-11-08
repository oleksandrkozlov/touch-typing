#ifndef TOUCH_TYPING_TEXT_FILER_HPP
#define TOUCH_TYPING_TEXT_FILER_HPP

#include <filesystem>
#include <string>

namespace touch_typing {

class TextFile {
public:
    explicit TextFile(const std::filesystem::path& filename);

    [[nodiscard]] auto asString() const noexcept -> const std::string&;

private:
    std::string m_text;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_TEXT_FILER_HPP
