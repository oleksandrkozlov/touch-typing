export module touch_typing:TextStorage;

import <iterator>;
import <string>;
import <utility>;
import <vector>;

export namespace touch_typing {

class TextStorage {
public:
    using Texts = std::vector<std::string>;

    // cppcheck-suppress passedByValue
    explicit TextStorage(Texts texts) noexcept
        : m_texts{std::move(texts)}
    {
    }

    [[nodiscard]] auto getText() const -> std::string
    {
        // TODO(unknown)
        return *std::cbegin(m_texts);
    }

private:
    Texts m_texts;
};

} // namespace touch_typing
