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

    bool isInited;

    void reformat();

public:
    explicit lexer(const std::string& input);
    token getNextToken();
    std::vector<token> getTokens();
    ~lexer() = default;
};


#endif //GUI_CALCULATOR_LEXER_H
