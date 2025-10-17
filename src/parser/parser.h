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
private:
    lexer lexer;
    token currentToken;
    double result;

    double calculate();
    explicit parser(const std::string& input);

public:
    static double parse(const std::string& input);
    ~parser() = default;
};


#endif //GUI_CALCULATOR_PARSER_H
