//
// Created by user on 15.10.2025.
//

#ifndef GUI_CALCULATOR_LEXER_H
#define GUI_CALCULATOR_LEXER_H

#include "../token/token.h"
#include <vector>

class lexer
{
private:
    std::vector<token> tokenStream;
    size_t index;

    void reformat();

public:
    lexer(const std::string& input);
    token getNextToken();
    std::vector<token> getTokens();
    ~lexer() = default;
};


#endif //GUI_CALCULATOR_LEXER_H
