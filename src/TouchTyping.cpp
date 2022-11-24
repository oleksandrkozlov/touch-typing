#define DOCOPT_HEADER_ONLY
#include <docopt/docopt.h>
#include <docopt/docopt_value.h>
#define SPDLOG_HEADER_ONLY
#include <spdlog/spdlog.h>

import <exception>;
import <filesystem>;
import <iterator>;
import <map>;
import <memory>;
import <string>;
import <utility>;
import touch_typing;

namespace {

constexpr auto usage = R"(
Usage:
    touch_typing [(-f | --file) <file>]

Options:
    -f, --file   Input file.
)";

} // namespace

auto main(int argc, char** argv) noexcept -> int
{
    try {
        spdlog::info("Welcome to Touch Typing!");

        const auto arguments =
            docopt::docopt(usage, {std::next(argv), std::next(argv, argc)});

        using namespace std::string_literals;

        const auto filename = arguments.at("<file>")
            ? arguments.at("<file>").asString()
            : "/usr/local/share/0001-text.txt"s;

        const auto text = touch_typing::TextFile{filename};
        auto texts = touch_typing::TextStorage::Texts{text.asString()};

        auto presenter = touch_typing::CursesPresenter{};

        auto textStorage = touch_typing::TextStorage{std::move(texts)};

        auto interactor = touch_typing::Interactor{textStorage, presenter};

        auto controller = touch_typing::Controller{interactor};

        controller.readSymbols();

        return 0;
    } catch (const std::exception& error) {
        try {
            spdlog::error(error.what());
        } catch (...) {
        }
    } catch (...) {
    }
    return 1;
}
