//
// Created by user on 17.10.2025.
//

#ifndef GUI_CALCULATOR_DYNAMICTOKENTEMPLATE_H
#define GUI_CALCULATOR_DYNAMICTOKENTEMPLATE_H

#include "token.h"

template <typename T>
std::ostream& operator<<(std::ostream& os, const dynamicToken<T>& t)
{
    os << "(Token type: ";
    switch (t.type)
    {
    case tokenType::PLUS:
        {
            os << "PLUS";
            break;
        }
    case tokenType::MINUS:
        {
            os << "MINUS";
            break;
        }
    case tokenType::MULTIPLY:
        {
            os << "MULTIPLY";
            break;
        }
    case tokenType::DIVIDE:
        {
            os << "DIVIDE";
            break;
        }
    case tokenType::OPEN_BRACKET:
        {
            os << "OPEN_BRACKET";
            break;
        }
    case tokenType::CLOSE_BRACKET:
        {
            os << "CLOSE_BRACKET";
            break;
        }
    case tokenType::EQUAL:
        {
            os << "EQUAL";
            break;
        }
    case tokenType::POWER:
        {
            os << "POWER";
            break;
        }
    case tokenType::ROOT:
        {
            os << "ROOT";
            break;
        }
    case tokenType::NUMBER:
        {
            os << "NUMBER";
            break;
        }
    case tokenType::IDENTIFIER:
        {
            os << "IDENTIFIER";
            break;
        }
    default:
        os << "UNKNOWN";
    }
    os << ", value: " << "\"" << t.value << "\", value type: " << typeid(T).name() << ")";
    return os;
}

#endif //GUI_CALCULATOR_DYNAMICTOKENTEMPLATE_H
