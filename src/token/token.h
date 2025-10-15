//
// Created by user on 15.10.2025.
//

#ifndef GUI_CALCULATOR_TOKEN_H
#define GUI_CALCULATOR_TOKEN_H

#include <string>
#include <iostream>

enum class tokenType
{
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    EQUAL,
    POWER,
    ROOT,
    NUMBER,
    IDENTIFIER
};


struct token
{
    tokenType type;
    std::string value;

    friend std::ostream& operator<<(std::ostream& os, const token& t);
};

#endif //GUI_CALCULATOR_TOKEN_H
