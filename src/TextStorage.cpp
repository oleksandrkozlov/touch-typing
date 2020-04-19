#include "TextStorage.hpp"

#include <iterator>
#include <utility>

namespace touch_typing {

// cppcheck-suppress passedByValue
TextStorage::TextStorage(Texts texts) noexcept
    : m_texts{std::move(texts)}
{
}

auto TextStorage::getText() const noexcept -> std::string
{
    // TODO(unknown)
    return *std::cbegin(m_texts);
}

} // namespace touch_typing
