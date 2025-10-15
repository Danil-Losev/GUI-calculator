//
// Created by user on 15.10.2025.
//

#include "token.h"

std::ostream& operator<<(std::ostream& os, const token& t)
{
    os << "(type: ";
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
    }
    os << ", value: " << "\"" << t.value << "\" " << ")";
    return os;
}
