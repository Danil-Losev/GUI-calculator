//
// Created by user on 15.10.2025.
//

#ifndef GUI_CALCULATOR_PARSER_H
#define GUI_CALCULATOR_PARSER_H

#include <vector>
#include <variant>
#include "../token/token.h"
#include "../lexer/lexer.h"
#include "../logger/logger.h"

class parser
{
public:
    static std::vector<std::variant<dynamicToken<double>, dynamicToken<std::string>>> parseToDynamicTokenStream(
        const std::vector<token>& tokens);
};


#endif //GUI_CALCULATOR_PARSER_H
