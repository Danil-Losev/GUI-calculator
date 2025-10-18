//
// Created by user on 18.10.2025.
//

#ifndef GUI_CALCULATOR_KEYBOARD_H
#define GUI_CALCULATOR_KEYBOARD_H

#include <QWidget>
#include <QGridLayout>

#include "key/key.h"
#include "../screen/screen.h"

class keyboard final : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(keyboard)

private:
    QGridLayout* layout;

    class screen* screenUI;

    void addKey(const QString& keyValue, int row, int col);

public:
    keyboard(class screen* screen, QWidget* parent = nullptr);
    ~keyboard() override = default;
};


#endif //GUI_CALCULATOR_KEYBOARD_H
