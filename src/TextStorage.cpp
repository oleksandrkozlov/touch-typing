#include "TextStorage.hpp"

namespace touch_typing {

TextStorage::TextStorage(Texts texts) noexcept
    : m_texts{std::move(texts)}
{
}

auto TextStorage::getText() const noexcept -> std::string
{
    // TODO
    return *std::cbegin(m_texts);
}

} // namespace touch_typing
