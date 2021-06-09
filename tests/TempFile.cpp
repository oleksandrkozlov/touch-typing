#include "TempFile.hpp"

#include <fmt/core.h>
#include <unistd.h>

#include <cstdlib>
#include <stdexcept>
#include <string>

namespace touch_typing {
TempFile::TempFile()
{
    auto templet = fmt::format(
        "{}/touch_typing_XXXXXX",
        std::filesystem::temp_directory_path().string());

    m_fileDescriptor = mkstemp(templet.data());
    const auto errorCode = -1;

    if (m_fileDescriptor == errorCode)
        throw std::runtime_error{"Cannot create a temp file."};

    m_path = std::filesystem::path{templet};
}

TempFile::~TempFile() noexcept
{
    close(m_fileDescriptor);
    std::filesystem::remove(m_path);
}

auto TempFile::getPath() const noexcept -> const std::filesystem::path&
{
    return m_path;
}

} // namespace touch_typing
