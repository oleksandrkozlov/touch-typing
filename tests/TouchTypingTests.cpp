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
public:
    auto getInteractor() noexcept -> touch_typing::Input&
    {
        return *m_interactor;
    }

private:
    auto onGotInputText(const std::string& inputText) -> void override
    {
        ASSERT_EQ(m_inputText, inputText);
    }

    auto onGotOutputResult(OutputResult outputResult) -> void override
    {
        ASSERT_EQ(outputResult.answer, OutputResult::Answer::Correct);
    }

    std::string m_inputText{"Hello, World!"};
    TextStorage m_textStorage{TextStorage::Texts{m_inputText}};
    std::unique_ptr<touch_typing::Input> m_interactor{
        std::make_unique<touch_typing::Interactor>(m_textStorage, *this)};
};

TEST_F(TouchTypingTests, shouldEnterAllSymbolsCorrectly) // NOLINT
{
    getInteractor().enterSymbol('H');
    getInteractor().enterSymbol('e');
    getInteractor().enterSymbol('l');
    getInteractor().enterSymbol('l');
    getInteractor().enterSymbol('o');
    getInteractor().enterSymbol(',');
    getInteractor().enterSymbol(' ');
    getInteractor().enterSymbol('W');
    getInteractor().enterSymbol('o');
    getInteractor().enterSymbol('r');
    getInteractor().enterSymbol('l');
    getInteractor().enterSymbol('d');
    getInteractor().enterSymbol('!');
}

} // namespace touch_typing
