
#include <QApplication>

#include "parser/parser.h"
#include "GUI/gui.h"

int main(int argc, char* argv[])
{
    if (argc >= 2)
    {
        if (strcmp(argv[1], "--input") == 0 && argc == 3)
        {
            const double result = parser(std::string(argv[2]), true).parse();
            std::cout << "Result: " << result << '\n';
            return 0;
        }
        std::cout << "Usage: " << argv[0] << " --input <expression>\n";
        return -1;
    }


    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("./styles/images/icon144.png"));
    gui graphicalInterface;
    graphicalInterface.show();
    return QApplication::exec();
}
