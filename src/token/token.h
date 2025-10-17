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


template <typename T>
struct dynamicToken
{
    tokenType type;
    T value;
};

struct token
{
    tokenType type;
    std::string value;

    friend std::ostream& operator<<(std::ostream& os, const token& t);
};

#include "dynamicTokenTemplate.h"

#endif //GUI_CALCULATOR_TOKEN_H
