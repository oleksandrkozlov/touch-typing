#include "TextFile.hpp"

#include "TempFile.hpp"

#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <string>

namespace touch_typing {
namespace {

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

} // namespace
} // namespace touch_typing
