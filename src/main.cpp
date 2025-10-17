
#include <QApplication>

#include "lexer/lexer.h"
#include "parser/parser.h"


int main(int argc, char* argv[])
{
    const auto tokens = lexer(argv[1]).getTokens();

    for (auto& token : tokens)
    {
        logger() << token << '\n';
    }

    for (auto& token : tokens)
    {
        logger() << token.value;
    }
    logger() << '\n';

    const auto parsedTokens = parser::parseToDynamicTokenStream(tokens);

    for (auto& token : parsedTokens)
    {
        std::visit([](auto&& arg)
                   {
                       logger() << arg << '\n';
                   },
                   token);
    }
}
