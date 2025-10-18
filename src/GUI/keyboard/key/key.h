//
// Created by user on 18.10.2025.
//

#ifndef GUI_CALCULATOR_KEY_H
#define GUI_CALCULATOR_KEY_H

#include <QPushButton>

class key final : public QPushButton
{
    Q_OBJECT

public:
    key(const QString& keyValue, QWidget* parent = nullptr);
signals:
    void keyClicked(const QString& keyValue);
};


#endif //GUI_CALCULATOR_KEY_H
