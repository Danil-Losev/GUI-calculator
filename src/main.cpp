
#include <QApplication>

#include "parser/parser.h"


int main(int argc, char* argv[])
{
    logger() << "Result: " << parser(std::string(argv[1])).parse() << '\n';
    return 0;
}
