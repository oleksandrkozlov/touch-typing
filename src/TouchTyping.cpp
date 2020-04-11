#include "StandartInput.hpp"
#include "StandartOutput.hpp"

#include <iostream>
#include <memory>

int main()
{
    auto input = std::unique_ptr<touch_typing::Input>{
        std::make_unique<touch_typing::StandartInput>()};

    auto output = std::unique_ptr<touch_typing::Output>{
        std::make_unique<touch_typing::StandartOutput>()};

    std::cout << input->read() << std::endl;

    return 0;
}
