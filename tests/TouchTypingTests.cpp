#include "Input.hpp"
#include "Interactor.hpp"
#include "Output.hpp"
#include "OutputResult.hpp"
#include "TextStorage.hpp"

#include <gtest/gtest.h>

#include <memory>
#include <string>

namespace touch_typing {

class TouchTypingTests : public testing::Test, public Output {
private:
    auto onGotInputText(std::string inputText) -> void override
    {
        ASSERT_EQ(m_inputText, inputText);
    }

    auto onGotOutputResult(OutputResult outputResult) -> void override
    {
        ASSERT_EQ(outputResult.answer, OutputResult::Answer::Correct);
    }

private:
    std::string m_inputText{"Hello, World!"};
    TextStorage m_textStorage{TextStorage::Texts{m_inputText}};

protected:
    std::unique_ptr<touch_typing::Input> m_interactor{
        std::make_unique<touch_typing::Interactor>(m_textStorage, *this)};
};

TEST_F(TouchTypingTests, shouldEnterAllSymbolsCorrectly)
{
    m_interactor->enterSymbol('H');
    m_interactor->enterSymbol('e');
    m_interactor->enterSymbol('l');
    m_interactor->enterSymbol('l');
    m_interactor->enterSymbol('o');
    m_interactor->enterSymbol(',');
    m_interactor->enterSymbol(' ');
    m_interactor->enterSymbol('W');
    m_interactor->enterSymbol('o');
    m_interactor->enterSymbol('r');
    m_interactor->enterSymbol('l');
    m_interactor->enterSymbol('d');
    m_interactor->enterSymbol('!');
}

} // namespace touch_typing
