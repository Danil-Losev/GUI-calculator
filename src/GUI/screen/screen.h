
//
// Created by user on 18.10.2025.
//

#ifndef GUI_CALCULATOR_SCREEN_H
#define GUI_CALCULATOR_SCREEN_H

#include "../../parser/parser.h"
#include <QLineEdit>

class screen final : public QLineEdit
{
    Q_OBJECT

public:
    screen(QWidget* parent = nullptr);

public slots:
    void onCalculate();
};


#endif //GUI_CALCULATOR_SCREEN_H
