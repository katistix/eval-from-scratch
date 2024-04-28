#include "Tokenizer.h"
#include <cctype>
#include <iostream>

/**
 * The constructor
 * - initializes the private variables input an position
 */
Tokenizer::Tokenizer(const std::string &input) : input(input), position(0) {}

/**
 * The tokenize method
 */
std::vector<Token> Tokenizer::tokenize()
{
    std::vector<Token> tokens; // the final list of tokens
    std::string currentToken;  // used when forming tokens with more than one char

    // go through each character in the input
    while (position < input.size())
    {
        skipWhitespace(); // skip all spaces

        char ch = input[position];

        // Decide the type of the token

        if (isOperator(ch))
        {
            // add the token to the list
            // - static_cast will look into the mapped "TokenTypes"
            // and transform the current char, from that char to the correct enum type
            // example: '=' becomes TokenType::EQUAL
            // - std::string(1, ch) converts the char into a string of length = 1
            tokens.push_back({static_cast<TokenType>(ch), std::string(1, ch)});
            position++;
        }
        else if (isNumber(ch))
        {
            // Form a new number, for now, only possitive integer
            currentToken.clear();
            currentToken += ch;
            position++;

            while (position < input.size() && isNumber(input[position]))
            {
                currentToken += input[position];
                position++;
            }

            // Add the number to the tokens
            tokens.push_back({TokenType::NUMBER, currentToken});
        }
        else
        {
            // if the token is not recognized, show an error
            std::cerr << "Unknown character: " << ch << std::endl;
            position++;
        }
    }

    return tokens;
}

/// METHODS TO DECIDE THE TOKEN TYPE

bool Tokenizer::isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool Tokenizer::isNumber(char ch)
{
    return std::isdigit(ch);
}

/// IGNORE WHITESPACE
void Tokenizer::skipWhitespace()
{
    while (position < input.size() && std::isspace(input[position]))
    {
        position++;
    }
}