#ifndef TOUCH_TYPING_TEMP_FILE_HPP
#define TOUCH_TYPING_TEMP_FILE_HPP

#include <cstdint>
#include <filesystem>

namespace touch_typing {

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

} // namespace touch_typing

#endif // TOUCH_TYPING_TEMP_FILE_HPP
