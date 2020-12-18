#include "Accounts.hpp"

#include "Account.hpp"
#include "BinaryStorage.hpp"
#include "TempFile.hpp"

#include <gtest/gtest.h>

#include <string>
#include <vector>

namespace touch_typing {
namespace {

TEST(BinaryStorageTests, shouldReadTextFile) // NOLINT
{
    const auto tempFile = TempFile{};
    const auto& filename = tempFile.getPath();
    auto expectedAccounts =
        Accounts{Account{"username"}, Account{"username"}};
    auto storage = BinaryStorage{filename};

    storage.save(expectedAccounts);
    const auto actualAccounts = storage.load<Accounts>();

    EXPECT_EQ(actualAccounts, expectedAccounts);
}

} // namespace
} // namespace touch_typing
