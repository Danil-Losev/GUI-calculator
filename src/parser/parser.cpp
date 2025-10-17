//
// Created by user on 15.10.2025.
//

#include "parser.h"
#include <cstdlib>


double parser::calculate()
{
}

parser::parser(const std::string& input) : lexer(input), currentToken(lexer.getNextToken()), result(0)
{
}

double parser::parse(const std::string& input)
{
    return parser(input).calculate();
}
