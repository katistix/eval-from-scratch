#include <iostream>
#include <fstream>
#include <string>
#include "Tokenizer/Tokenizer.h"

int main()
{

    std::string sourceCode;

    std::getline(std::cin, sourceCode);

    // Create a Tokenizer object with the source code
    Tokenizer tokenizer(sourceCode);

    // Tokenize the source code
    std::vector<Token> tokens = tokenizer.tokenize();

    // Print the tokens
    for (const Token &token : tokens)
    {
        std::cout << "Type: ";
        switch (token.type)
        {
        case TokenType::IDENTIFIER:
            std::cout << "Identifier";
            break;
        case TokenType::NUMBER:
            std::cout << "Number";
            break;
        case TokenType::PLUS:
            std::cout << "Plus";
            break;
        case TokenType::MINUS:
            std::cout << "Minus";
            break;
        case TokenType::MULTIPLY:
            std::cout << "Multiply";
            break;
        case TokenType::DIVIDE:
            std::cout << "Divide";
            break;
        case TokenType::UNKNOWN:
            std::cout << "Unknown";
            break;
        }
        std::cout << ", Value: " << token.value << std::endl;
    }
}