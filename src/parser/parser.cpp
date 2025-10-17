//
// Created by user on 15.10.2025.
//

#include "parser.h"
#include <cstdlib>

std::vector<std::variant<dynamicToken<double>, dynamicToken<std::string>>> parser::parseToDynamicTokenStream(
    const std::vector<token>& tokens)
{
    std::vector<std::variant<dynamicToken<double>, dynamicToken<std::string>>> parsed;
    for (const auto& token : tokens)
    {
        if (token.type == tokenType::NUMBER)
        {
            parsed.push_back(dynamicToken{token.type, std::strtod(token.value.c_str(), nullptr)});
        }
        else
        {
            parsed.push_back(dynamicToken{token.type, token.value});
        }
    }
    return parsed;
}
