#include "TextFile.hpp"

#include <gtest/gtest.h>
#include <unistd.h>

#include <cstdint>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>

namespace touch_typing {
namespace {

class TempFile {
public:
    TempFile();

    TempFile(TempFile&& other) noexcept = delete;
    TempFile(const TempFile&) = delete;

    auto operator=(TempFile&& other) noexcept -> TempFile& = delete;
    auto operator=(const TempFile& other) -> TempFile& = delete;

    ~TempFile() noexcept;

    [[nodiscard]] auto getPath() const noexcept
        -> const std::filesystem::path&;

private:
    std::int32_t m_fileDescriptor{};
    std::filesystem::path m_path;
};

TEST(TextFileTests, shouldReadTextFile) // NOLINT
{
    using namespace std::string_literals;
    const auto tempFile = TempFile{};
    const auto& filename = tempFile.getPath();
    const auto text = "test"s;

    {
        auto file = std::ofstream{filename};
        file << text;
    }

    const auto file = TextFile{filename};
    EXPECT_EQ(file.asString(), text);
}

TempFile::TempFile()
{
    auto templet = std::filesystem::temp_directory_path().string() +
        "/touch_typing_XXXXXX";

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

} // namespace
} // namespace touch_typing
