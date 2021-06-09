#include "Account.hpp"
#include "Accounts.hpp"
#include "BinaryStorage.hpp"
#include "Controller.hpp"
#include "CursesPresenter.hpp"
#include "Input.hpp"
#include "Interactor.hpp"
#include "Output.hpp"
#include "TextFile.hpp"
#include "TextStorage.hpp"

#include <docopt/docopt.h>
#include <docopt/docopt_value.h>
#include <spdlog/fmt/bundled/format.h>
#include <spdlog/spdlog.h>

#include <exception>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace {

constexpr auto usage = R"(
Usage:
    touch_typing [(-f | --file) <file>]

Options:
    -f, --file   Input file.
)";

} // namespace

auto main(const int argc, const char** const argv) noexcept -> int
{
    try {
        spdlog::info("Welcome to Touch Typing!");

        auto accountStorage =
            touch_typing::BinaryStorage{"account-storage.data"};

        const auto accounts = accountStorage.load<touch_typing::Accounts>();

        if (std::empty(accounts)) {
            spdlog::info("Enter username:");
            std::string username;
            std::cin >> username;
            const auto account = touch_typing::Account{std::move(username)};
            accountStorage.save(touch_typing::Accounts{account});
        } else {
            spdlog::info("Select username:");
            for (std::size_t i = 0; i < std::size(accounts); ++i) {
                spdlog::info("{}) {}", i, accounts.at(i).getUsername());
            }
            std::size_t userId = 0;
            std::cin >> userId;
            spdlog::info("Welcome, {}!", accounts.at(userId).getUsername());
        }

        const auto arguments =
            docopt::docopt(usage, {std::next(argv), std::next(argv, argc)});

        using namespace std::string_literals;

        const auto filename = arguments.at("<file>")
            ? arguments.at("<file>").asString()
            : TOUCH_TYPING_DATA_DIR + "/0001-text.txt"s;

        const auto text = touch_typing::TextFile{filename};
        auto texts = touch_typing::TextStorage::Texts{text.asString()};

        auto presenter = std::unique_ptr<touch_typing::Output>{
            std::make_unique<touch_typing::CursesPresenter>()};

        auto textStorage = touch_typing::TextStorage{std::move(texts)};

        auto interactor = std::unique_ptr<touch_typing::Input>{
            std::make_unique<touch_typing::Interactor>(
                textStorage, *presenter)};

        auto controller = touch_typing::Controller{*interactor};

        controller.readSymbols();

        return 0;
    } catch (const std::exception& error) {
        spdlog::error(error.what());
        return 1;
    } catch (...) {
        spdlog::error("Unexpected error.");
        return 1;
    }
}
