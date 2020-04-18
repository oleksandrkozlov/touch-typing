#include "Controller.hpp"
#include "CursesPresenter.hpp"
#include "Interactor.hpp"
#include "TextStorage.hpp"

#include <memory>

int main()
{
    auto presenter = std::unique_ptr<touch_typing::Output>{
        std::make_unique<touch_typing::CursesPresenter>()};

    auto texts = touch_typing::TextStorage::Texts{
        "To be, or not to be, that is the question."};

    auto textStorage = touch_typing::TextStorage{std::move(texts)};

    auto interactor = std::unique_ptr<touch_typing::Input>{
        std::make_unique<touch_typing::Interactor>(
            textStorage, *presenter)};

    auto controller = touch_typing::Controller{*interactor};

    controller.readSymbols();

    return 0;
}
