//
// Created by user on 15.10.2025.
//

#include "parser.h"

void parser::setNextToken()
{
    currentToken = lexer.getNextToken();
}

int parser::getAtomPriority(const tokenType type)
{
    if (type == tokenType::END_OF_INPUT)
        return -1;
    switch (type)
    {
    case tokenType::PLUS:
    case tokenType::MINUS: return 10;
    case tokenType::MULTIPLY:
    case tokenType::DIVIDE: return 20;
    case tokenType::POWER:
    case tokenType::ROOT: return 30;
    default: return -1;
    }
}

std::unique_ptr<Node> parser::parsePrimaryExpression()
{
    if (currentToken.type == tokenType::PLUS || currentToken.type == tokenType::MINUS)
    {
        tokenType op = currentToken.type;
        setNextToken();
        auto operand = parsePrimaryExpression();
        return std::make_unique<UnaryOpNode>(op, std::move(operand));
    }

    if (currentToken.type == tokenType::NUMBER)
    {
        double value = std::stod(currentToken.value);
        setNextToken();
        return std::make_unique<NumberNode>(value);
    }

    if (currentToken.type == tokenType::OPEN_BRACKET)
    {
        setNextToken();
        auto expression = parseExpression(0);
        if (currentToken.type != tokenType::CLOSE_BRACKET)
            throw std::runtime_error("Expected ')'");
        setNextToken();
        return expression;
    }
    throw std::runtime_error("Unexpected token: " + currentToken.value);
}

std::unique_ptr<Node> parser::parseExpression(const int minPriority)
{
    auto left = parsePrimaryExpression();

    while (true)
    {
        if (currentToken.type == tokenType::END_OF_INPUT)
            break;

        const int priority = getAtomPriority(currentToken.type);
        if (priority <= minPriority)
            break;

        tokenType operation = currentToken.type;
        setNextToken();

        const int nextMin = priority + (operation == tokenType::POWER ? 0 : 1);
        auto right = parseExpression(nextMin);

        left = std::make_unique<BinaryOpNode>(std::move(left), operation, std::move(right));
    }

    return left;
}

parser::parser(const std::string& input, const bool isTUI) : lexer(input), currentToken(lexer.getNextToken()),
                                                             result(0), isError(false), error(""), isTUI(isTUI)
{
}

bool parser::isErrorOccured(std::string& outErrorMessage) const
{
    outErrorMessage = error;
    return isError;
}

double parser::parse()
{
    isError = false;
    try
    {
        result = parseExpression()->eval();
    }
    catch (const std::exception& e)
    {
        logger() << e.what() << '\n';
        isError = true;
        error = e.what();
    }
    if (isError && isTUI)
    {
        std::cout << "Error: " << error << '\n';
    }
    return result;
}
