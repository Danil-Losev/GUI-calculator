//
// Created by user on 18.10.2025.
//

#include "screen.h"
#include <QFile>

screen::screen(QWidget* parent) : QLineEdit(parent)
{
    setFixedHeight(50);
    setText(" ");

    QFile styleSheet("./styles/screen/screen.qss");
    if (styleSheet.open(QFile::ReadOnly))
    {
        setStyleSheet(styleSheet.readAll());
        styleSheet.close();
    }
    else
    {
        logger() << "Failed to load stylesheet for screen\n";
    }
}

void screen::onCalculate()
{
    try
    {
        parser parserObj(this->text().toStdString(), false);
        const double result = parserObj.parse();
        std::string error;
        const bool isError = parserObj.isErrorOccured(error);
        if (!isError)
        {
            this->setText(std::to_string(result).c_str());
        }
        else
        {
            this->setText(error.c_str());
        }
    }
    catch (const std::exception& e)
    {
        this->setText(e.what());
    }
}
