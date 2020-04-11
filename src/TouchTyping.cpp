#include "Interactor.hpp"
#include "StandardOutput.hpp"

#include <iostream>
#include <memory>

int main()
{
    auto output = std::unique_ptr<touch_typing::Output>{
        std::make_unique<touch_typing::StandardOutput>()};

    auto interactor = touch_typing::Interactor{*output};

    return 0;
}
