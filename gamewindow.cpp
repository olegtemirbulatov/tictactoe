#include "gamewindow.h"
#include <QMessageBox>

GameWindow::GameWindow(int _dim, const QVector<QString> *_gamers, QWidget *parent) :
    QDialog(parent), dim(_dim), lastClickedFieldButton(nullptr)
{
    gamers = new QVector<QString>(*_gamers);

    gamerLabel = new QLabel("Ход игрока: ");
    gamerName = new QLabel(gamers->at(0));
    hlayout1 = new QHBoxLayout();
    hlayout1->addWidget(gamerLabel);
    hlayout1->addWidget(gamerName);

    turnLabel = new QLabel("Номер хода: ");
    turnNumber = new QLabel("1");
    hlayout2 = new QHBoxLayout();
    hlayout2->addWidget(turnLabel);
    hlayout2->addWidget(turnNumber);

    field = new QGridLayout();
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            QPushButton *button = new QPushButton(this);
            field->addWidget(button, i, j);
            QObject::connect(button, &QPushButton::clicked, this, GameWindow::push_fieldButton);
        }
    }

    exitButton = new QPushButton("Завершить и выйти", this);
    turnButton = new QPushButton("Сделать ход", this);

    QObject::connect(exitButton, &QPushButton::clicked, this, GameWindow::push_exitButton);
    QObject::connect(turnButton, &QPushButton::clicked, this, GameWindow::push_turnButton);

    hlayout3 = new QHBoxLayout();
    hlayout3->addWidget(exitButton);
    hlayout3->addWidget(turnButton);

    vlayout = new QVBoxLayout(this);
    vlayout->addLayout(hlayout1);
    vlayout->addLayout(hlayout2);
    vlayout->addLayout(field);
    vlayout->addLayout(hlayout3);
    setLayout(vlayout);

    this->show();
}

GameWindow::~GameWindow() {}

void GameWindow::clearActiveButtons()
{
    for (int i = 0; i < dim; ++i)
    {
        for (int j = 0; j < dim; ++j)
        {
            QWidget* widget = field->itemAtPosition(i, j)->widget();
            QPushButton *fieldButton = dynamic_cast<QPushButton*>(widget);
            if (fieldButton && fieldButton->isEnabled())
            {
                fieldButton->setText("");
            }
        }
    }
}

void GameWindow::push_fieldButton()
{
    GameWindow::clearActiveButtons();
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton)
    {
        if (clickedButton->isEnabled())
        {
            if (turnNumber->text().toInt() % 2 == 1)
            {
                clickedButton->setText("X");
            }
            else
            {
                clickedButton->setText("O");
            }
            lastClickedFieldButton = clickedButton;
        }
    }
}

void GameWindow::push_exitButton()
{
    QMessageBox msgBox = QMessageBox(QMessageBox::Question,
                                     "Подтверждение действия",
                                     "Уверены, что хотите выйти из игры?",
                                     QMessageBox::Yes|QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Yes)
    {
        this->deleteLater();
    }
}

void GameWindow::push_turnButton()
{
    if (lastClickedFieldButton)
    {
        lastClickedFieldButton->setEnabled(false);
        lastClickedFieldButton = nullptr;
    }

    QString next_gamer;
    if (gamerName->text() == gamers->at(0))
        next_gamer = gamers->at(1);
    else
        next_gamer = gamers->at(0);
    gamerName->setText(next_gamer);

    int turn_num = turnNumber->text().toInt();
    ++turn_num;
    turnNumber->setText(QString::number(turn_num));
}
