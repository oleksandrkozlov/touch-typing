#include "Interactor.hpp"
#include "StandartOutput.hpp"

#include <iostream>
#include <memory>

int main()
{
    auto output = std::unique_ptr<touch_typing::Output>{
        std::make_unique<touch_typing::StandartOutput>()};

    auto interactor = touch_typing::Interactor{*output};

    return 0;
}
