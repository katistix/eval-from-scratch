#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <cstddef>
#include <string>
#include <vector>

// Enumerate the token types
enum class TokenType
{
    IDENTIFIER = -1,
    NUMBER = -2,
    PLUS = '+',
    MINUS = '-',
    MULTIPLY = '*',
    DIVIDE = '/',

    UNKNOWN = -99

};

// The structure of a Token
struct Token
{
    TokenType type;
    std::string value;
};

// Now we ne the actual Tokenizer
class Tokenizer
{
public:
    Tokenizer(const std::string &input);
    std::vector<Token> tokenize();

private:
    std::string input;
    size_t position;

    // methods to decide the token type
    bool isOperator(char ch);
    bool isNumber(char ch);

    void skipWhitespace();
};

#endif