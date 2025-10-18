//
// Created by user on 15.10.2025.
//

#ifndef GUI_CALCULATOR_PARSER_H
#define GUI_CALCULATOR_PARSER_H

#include <vector>
#include <variant>

#include "Node.h"
#include "../token/token.h"
#include "../lexer/lexer.h"
#include "../logger/logger.h"

class parser
{
private:
    lexer lexer;
    token currentToken;
    double result;

    void setNextToken();
    static int getAtomPriority(tokenType type);
    std::unique_ptr<Node> parsePrimaryExpression();
    std::unique_ptr<Node> parseExpression(int minPriority = 0);

public:
    explicit parser(const std::string& input);
    double parse();
    ~parser() = default;
};


#endif //GUI_CALCULATOR_PARSER_H
