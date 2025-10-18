//
// Created by user on 17.10.2025.
//

#ifndef GUI_CALCULATOR_NODE_H
#define GUI_CALCULATOR_NODE_H

#include "../token/token.h"

class Node
{
public:
    virtual double eval() = 0;
    virtual ~Node() = default;
};


class NumberNode final : public Node
{
private:
    double value;

public:
    explicit NumberNode(const double value) : value(value)
    {
    };
    double eval() override;
};

class BinaryOpNode final : public Node
{
private:
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    tokenType operation;

public:
    BinaryOpNode(std::unique_ptr<Node> left, const tokenType operation, std::unique_ptr<Node> right)
        : left(std::move(left)), right(std::move(right)), operation(operation)
    {
    }

    double eval() override;
};

class UnaryOpNode final : public Node
{
private:
    tokenType operation;
    std::unique_ptr<Node> operand;

public:
    UnaryOpNode(const tokenType operation, std::unique_ptr<Node> operand)
        : operation(operation), operand(std::move(operand))
    {
    }

    double eval() override;
};
#endif //GUI_CALCULATOR_NODE_H
