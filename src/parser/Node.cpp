//
// Created by user on 17.10.2025.
//

#include "Node.h"

double NumberNode::eval()
{
    return value;
}

double BinaryOpNode::eval()
{
    switch (operation)
    {
    case tokenType::PLUS:
        return left->eval() + right->eval();
    case tokenType::MINUS:
        return left->eval() - right->eval();
    case tokenType::MULTIPLY:
        return left->eval() * right->eval();
    case tokenType::DIVIDE:
        {
            if (right->eval() == 0)
            {
                throw std::runtime_error("Division by zero");
            }
            return left->eval() / right->eval();
        }
    case tokenType::POWER:
        {
            if (right->eval() == 0)
            {
                return 1;
            }
            return std::pow(left->eval(), right->eval());
        }
    case tokenType::ROOT:
        {
            if (right->eval() == 0)
            {
                throw std::runtime_error("Root of zero");
            }
            if (right->eval() < 0)
            {
                throw std::runtime_error("Root of negative number");
            }
            return std::pow(left->eval(), 1.0 / right->eval());
        }
    default:
        throw std::runtime_error("Unknown operation BinaryOpNode");
    }
}

double UnaryOpNode::eval()
{
    switch (operation)
    {
    case tokenType::PLUS:
        return operand->eval();
    case tokenType::MINUS:
        return -operand->eval();
    case tokenType::ROOT:
        {
            if (operand->eval() == 0)
            {
                throw std::runtime_error("Root of zero");
            }
            if (operand->eval() < 0)
            {
                throw std::runtime_error("Root of negative number");
            }
            return std::pow(operand->eval(), 1.0 / 2);
        }
    default:
        throw std::runtime_error("Unknown operation UnaryOpNode");
    }
}
