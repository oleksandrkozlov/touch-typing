#ifndef TOUCH_TYPING_TEXT_STORAGE_HPP
#define TOUCH_TYPING_TEXT_STORAGE_HPP

#include <string>
#include <vector>

namespace touch_typing {

class TextStorage {
public:
    using Texts = std::vector<std::string>;

    explicit TextStorage(Texts texts) noexcept;

    [[nodiscard]] auto getText() const noexcept -> std::string;

private:
    Texts m_texts;
};

} // namespace touch_typing

#endif // TOUCH_TYPING_TEXT_STORAGE_HPP
