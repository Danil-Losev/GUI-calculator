//
// Created by user on 15.10.2025.
//

#include "lexer.h"
#include <iostream>
#include "../logger/logger.h"


void lexer::reformat()
{
    std::vector<token> newTokens;
    for (int i = 0; i < tokenStream.size(); i++)
    {
        newTokens.push_back(tokenStream[i]);
        if (i < tokenStream.size() - 1 && tokenStream[i].type == tokenType::NUMBER && tokenStream[i + 1].type ==
            tokenType::IDENTIFIER)
        {
            newTokens.push_back(token{tokenType::MULTIPLY, "*"});
        }
    }
    tokenStream = newTokens;
}

lexer::lexer(const std::string& input)
{
    if (input.empty())
    {
        return;
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (std::isspace(input[i]))
        {
            continue;
        }
        if (std::isdigit(input[i]))
        {
            std::string number;
            while ((std::isdigit(input[i]) || input[i] == ',') && i < input.size())
            {
                number += input[i];
                i++;
            }
            tokenStream.push_back(token{tokenType::NUMBER, number});
            i--;
            continue;
        }
        if (std::isalpha(input[i]))
        {
            std::string identifier;
            while (std::isalpha(input[i]) && i < input.size())
            {
                identifier += input[i];
                i++;
            }
            tokenStream.push_back(token{tokenType::IDENTIFIER, identifier});
            i--;
            continue;
        }
        switch (input[i])
        {
        case '+':
            {
                tokenStream.push_back(token{tokenType::PLUS, "+"});
                break;
            }
        case '-':
            {
                tokenStream.push_back(token{tokenType::MINUS, "-"});
                break;
            }
        case '*':
            {
                tokenStream.push_back(token{tokenType::MULTIPLY, "*"});
                break;
            }
        case '/':
            {
                tokenStream.push_back(token{tokenType::DIVIDE, "/"});
                break;
            }
        case '(':
            {
                tokenStream.push_back(token{tokenType::OPEN_BRACKET, "("});
                break;
            }
        case ')':
            {
                tokenStream.push_back(token{tokenType::CLOSE_BRACKET, ")"});
                break;
            }
        case '=':
            {
                tokenStream.push_back(token{tokenType::EQUAL, "="});
                break;
            }
        case '^':
            {
                tokenStream.push_back(token{tokenType::POWER, "^"});
                break;
            }
        default:
            {
                std::cout << "Unknown token: " << input[i] << '\n';
                break;
            }
        }
    }
    reformat();
    logger() << tokenStream.size() << " tokens found\n";
}

std::vector<token> lexer::getTokens()
{
    return tokenStream;
}
