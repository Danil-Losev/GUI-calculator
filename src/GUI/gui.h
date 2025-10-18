//
// Created by user on 15.10.2025.
//

#ifndef GUI_CALCULATOR_GUI_H
#define GUI_CALCULATOR_GUI_H

#include <QMainWindow>
#include <QLayout>
#include <QWidget>

#include "keyboard/keyboard.h"

class gui final : public QMainWindow
{
    Q_OBJECT

private:
    keyboard* keyboardUI;
    class screen* screenUI;
    QBoxLayout* layout;
    QWidget* centralWidget;

public:
    gui(QWidget* parent = nullptr);
    ~gui() override = default;
};


#endif //GUI_CALCULATOR_GUI_H
