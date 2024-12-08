#include "fieldbutton.h"

FieldButton::FieldButton(QWidget *parent)
    : QPushButton(parent)
{
    const QSize btnSize = QSize(110, 110);
    this->setFixedSize(btnSize);
    this->setStyleSheet("background-color: white;"
                        "font-size: 54pt;"
                        "height: 48pt;"
                        "width: 120px;"
                        "border-style: outset;"
                        "border-width: 2px;"
                        "border-color: black;");
}
