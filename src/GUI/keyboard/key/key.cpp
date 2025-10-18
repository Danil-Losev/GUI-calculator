//
// Created by user on 18.10.2025.
//

#include "key.h"
#include <QFile>

key::key(const QString& keyValue, QWidget* parent) : QPushButton(keyValue, parent)
{
    connect(this, &QPushButton::clicked, [this, keyValue]()
    {
        emit keyClicked(keyValue);
    });

    QFile styleSheet("./styles/key/key.qss");
    if (styleSheet.open(QFile::ReadOnly))
    {
        setStyleSheet(styleSheet.readAll());
        styleSheet.close();
    }
}
