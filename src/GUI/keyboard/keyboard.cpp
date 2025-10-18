//
// Created by user on 18.10.2025.
//

#include "keyboard.h"
#include <QLineEdit>
#include <QFile>

#define KEY_HEIGHT 50
#define KEY_WIDTH 50
#define SPACE_BETWEEN_KEYS 4

void keyboard::addKey(const QString& keyValue, int row, int col)
{
    const auto curKey = new key(keyValue);
    curKey->setFixedSize(KEY_WIDTH, KEY_HEIGHT);
    layout->addWidget(curKey, row, col);
    connect(curKey, &key::keyClicked, [this, keyValue]()
    {
        screenUI->setText(screenUI->text() + keyValue);
    });
}

keyboard::keyboard(class screen* screen, QWidget* parent) : QWidget(parent)
{
    screenUI = screen;
    layout = new QGridLayout(this);
    setLayout(layout);
    setFixedSize(5 * KEY_WIDTH + 4 * SPACE_BETWEEN_KEYS, 5 * KEY_HEIGHT + 4 * SPACE_BETWEEN_KEYS);
    layout->setSpacing(SPACE_BETWEEN_KEYS);


    const QString keys[3][3] = {
        {"7", "8", "9"},
        {"4", "5", "6"},
        {"1", "2", "3"},
    };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            addKey(keys[i][j], i + 1, j);
        }
    }
    addKey(QString('/'), 0, 0);
    addKey(QString('*'), 0, 1);
    addKey(QString('-'), 0, 2);
    addKey(QString('+'), 0, 3);
    addKey(QString('^'), 1, 3);
    addKey(QString('('), 2, 3);
    addKey(QString(')'), 3, 3);
    addKey(QString("v"), 1, 4);
    addKey(QString(','), 4, 3);

    auto* zeroKey = new key("0", this);
    zeroKey->setObjectName("zero");
    zeroKey->setFixedSize(3 * KEY_WIDTH, KEY_HEIGHT);
    layout->addWidget(zeroKey, 4, 0, 1, 3);
    connect(zeroKey, &key::keyClicked, [this]()
    {
        screenUI->setText(screenUI->text() + "0");
    });

    auto* equalKey = new key("=", this);
    equalKey->setObjectName("equal");
    equalKey->setFixedSize(KEY_WIDTH, 2 * KEY_HEIGHT);
    layout->addWidget(equalKey, 3, 4, 2, 1);
    connect(equalKey, &key::keyClicked, this->screenUI, &screen::onCalculate);

    auto* clearKey = new key("Clr", this);
    clearKey->setObjectName("clear");
    clearKey->setFixedSize(KEY_WIDTH, KEY_HEIGHT);
    layout->addWidget(clearKey, 0, 4);
    connect(clearKey, &key::keyClicked, [this]()
    {
        screenUI->setText("");
    });

    auto* delKey = new key("Del", this);
    delKey->setObjectName("del");
    delKey->setFixedSize(KEY_WIDTH, KEY_HEIGHT);
    layout->addWidget(delKey, 2, 4);
    connect(delKey, &key::keyClicked, [this]()
    {
        screenUI->setText(screenUI->text().left(screenUI->text().size() - 1));
    });

    QFile styleSheet("./styles/keyboard/keyboard.qss");
    if (styleSheet.open(QFile::ReadOnly))
    {
        setStyleSheet(styleSheet.readAll());
        styleSheet.close();
    }
    else
    {
        logger() << "Failed to load stylesheet for keyboard\n";
    }
}
