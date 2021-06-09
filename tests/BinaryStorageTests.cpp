#include "BinaryStorage.hpp"

#include "TempFile.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <string>

namespace touch_typing {
namespace {

struct Data {
    std::string string;
    std::uint32_t number = 0;

    template<typename Archive>
    void serialize(
        Archive& archive,
        [[maybe_unused]] const unsigned int version)
    {
        archive& string;
        archive& number;
    }
};

auto operator==(const Data& lhs, const Data& rhs) noexcept -> bool
{
    return lhs.string == rhs.string && lhs.number == rhs.number;
}

TEST(BinaryStorageTests, shouldReadTextFile) // NOLINT
{
    const auto tempFile = TempFile{};
    const auto& filename = tempFile.getPath();
    const auto expectedData = Data{"test", 322};
    auto storage = BinaryStorage{filename};
    storage.save(expectedData);
    const auto data = storage.load<Data>();

    EXPECT_EQ(data, expectedData);
}

} // namespace
} // namespace touch_typing
