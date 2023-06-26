#include "scanner.hpp"
#include <gtest/gtest.h>
#include <sstream>

TEST(ScannerTests, ScanTokenAtPosTest)
{
    struct SingleTokenTest
    {
        std::string input;
        Token expected_tok;
        std::string expected_lexeme;
    };

    SingleTokenTest tests[] = {
        {"(", Token::L_PAREN, "("},
        {")", Token::R_PAREN, ")"},
    };

    size_t n = sizeof(tests) / sizeof(SingleTokenTest);
    for (size_t i = 0; i < n; i++) {
        auto &test = tests[i];
        Scanner scanner(new std::istringstream(test.input));
        Lexeme lex;
        ASSERT_TRUE(scanner.ScanTokenAtPos(lex));
        ASSERT_EQ(lex.tok, test.expected_tok);
        ASSERT_EQ(lex.str, test.expected_lexeme);
    }
}