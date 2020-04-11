#include "Controller.hpp"
#include "StandardInteractor.hpp"
#include "StandardPresenter.hpp"

#include <iostream>
#include <memory>

int main()
{
    auto presenter = std::unique_ptr<touch_typing::Output>{
        std::make_unique<touch_typing::StandardPresenter>()};

    auto interactor = std::unique_ptr<touch_typing::Input>{
        std::make_unique<touch_typing::StandardInteractor>(*presenter)};

    auto controller = touch_typing::Controller{*interactor};

    controller.enterSymbols("Hello , World!");

    return 0;
}
