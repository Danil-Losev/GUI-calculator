#include <iostream>
#include <QApplication>
#include <QPushButton>

#include "lexer/lexer.h"
#include "logger/logger.h"


int main(int argc, char* argv[])
{
    const auto tokens = lexer("112+(2a+a)+12=0").getTokens();

    for (auto& token : tokens)
    {
        logger() << token << '\n';
    }

    for (auto& token : tokens)
    {
        logger() << token.value;
    }

    // QApplication a(argc, argv);
    // QPushButton button("Hello world!", nullptr);
    // button.resize(200, 100);
    // button.show();
    // return QApplication::exec();
}
