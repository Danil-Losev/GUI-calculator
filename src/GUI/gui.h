//
// Created by user on 15.10.2025.
//

#ifndef GUI_CALCULATOR_GUI_H
#define GUI_CALCULATOR_GUI_H

#include <QMainWindow>

class gui final : public QMainWindow
{
    Q_OBJECT

private:

public:
    gui(QWidget* parent = nullptr);
    ~gui() override = default;
};


#endif //GUI_CALCULATOR_GUI_H
