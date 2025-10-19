//
// Created by user on 15.10.2025.
//

#include "gui.h"
#include <QFile>
#include "../logger/logger.h"

gui::gui(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("Calculator");
    setFixedSize(50 * 5 + 4 * 3 + 30, 50 * 5 + 4 * 3 + 30 + 50 + 10);


    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    layout = new QVBoxLayout(centralWidget);

    screenUI = new class screen(this);
    keyboardUI = new keyboard(screenUI, this);


    layout->addWidget(screenUI);
    layout->addWidget(keyboardUI);
    centralWidget->setLayout(layout);

    QFile styleSheet("./styles/GUI/gui.qss");
    if (styleSheet.open(QFile::ReadOnly))
    {
        setStyleSheet(styleSheet.readAll());
        styleSheet.close();
    }
    else
    {
        logger() << "Failed to load stylesheet for GUI\n";
    }
}

