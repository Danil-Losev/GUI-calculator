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
        if (i < tokenStream.size() - 1 && tokenStream[i].type == tokenType::NUMBER &&
            (tokenStream[i + 1].type == tokenType::IDENTIFIER
                || tokenStream[i + 1].type == tokenType::OPEN_BRACKET
                || tokenStream[i + 1].type == tokenType::ROOT))
        {
            newTokens.push_back(token{tokenType::MULTIPLY, "*"});
        }
        if (i < tokenStream.size() - 1
            && (tokenStream[i + 1].type == tokenType::NUMBER || tokenStream[i + 1].type == tokenType::IDENTIFIER)
            && tokenStream[i].type == tokenType::CLOSE_BRACKET)
        {
            newTokens.push_back(token{tokenType::MULTIPLY, "*"});
        }

        if (i >= 1 && tokenStream[i - 1].type == tokenType::MINUS)
        {
            bool isUnaryMinus = false;
            if (i == 1)
                isUnaryMinus = true;
            else
            {
                const auto prev = tokenStream[i - 2].type;
                if (prev != tokenType::NUMBER && prev != tokenType::IDENTIFIER &&
                    prev != tokenType::CLOSE_BRACKET && prev != tokenType::END_OF_INPUT)
                {
                    // prev == tokenType::PLUS || prev == tokenType::MINUS || prev == tokenType::MULTIPLY ||
                    // prev == tokenType::DIVIDE || prev == tokenType::OPEN_BRACKET || prev == tokenType::EQUAL ||
                    // prev == tokenType::POWER
                    isUnaryMinus = true;
                }
            }

            if (isUnaryMinus && tokenStream[i].type == tokenType::NUMBER)
            {
                if (!newTokens.empty())
                    newTokens.pop_back();
                if (!newTokens.empty() && newTokens.back().type == tokenType::MINUS)
                    newTokens.pop_back();
                newTokens.push_back(token{tokenType::NUMBER, "-" + tokenStream[i].value});
            }
        }
    }
    tokenStream = newTokens;
    isInited = true;
}

lexer::lexer(const std::string& input) : index(0), isInited(false)
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
            while ((std::isdigit(input[i]) || input[i] == ',' || input[i] == '.') && i < input.size())
            {
                if (input[i] == ',')
                {
                    number += '.';
                    i++;
                    continue;
                }
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
            if (identifier == "v" || identifier == "sqrt")
            {
                tokenStream.push_back(token{tokenType::ROOT, "sqrt"});
                i--;
                continue;
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
        case '%':
            {
                tokenStream.push_back(token{tokenType::PERCENT, "%"});
                break;
            }
        default:
            {
                logger() << "Unknown token: " << input[i] << '\n';
                break;
            }
        }
    }
    reformat();
    isInited = true;
}

token lexer::getNextToken()
{
    if (!isInited)
    {
        throw std::runtime_error("Lexer is not initialized");
    }
    if (index >= tokenStream.size()) return {tokenType::END_OF_INPUT, "end"};
    return tokenStream.at(index++);
}

std::vector<token> lexer::getTokens()
{
    if (!isInited)
    {
        throw std::runtime_error("Lexer is not initialized");
    }
    return tokenStream;
}
