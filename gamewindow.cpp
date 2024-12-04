#include "gamewindow.h"
#include "board.h"
#include <QMessageBox>

GameWindow::GameWindow(UIGame *game, QWidget *parent) :
    QDialog(parent), dim(_dim), lastClickedFieldButton(nullptr)
{
    gamers = new QVector<QString> {
        game->getPlayer(0),
        game->getPlayer(1)
    };

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
    int dim = game->getDimension();
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

    int index = field->indexOf(lastClickedFieldButton);
    int x, y, _;
    field->getItemPosition(index, &x, &y, &_, &_);
    IBoard::PositionType pos{x, y};
    IBoard::Mark mark;
    auto currentMark = m_board->getMark(pos);
    if (currentMark == IBoard::MARK_EMPTY)
    {
        if (gamerName->text() == gamers->at(0)) mark = IBoard::MARK_X;
        else mark = IBoard::MARK_O;
        game->setMark(pos, mark);
    }

    if (game->ifPlayerWin())
    {
        QMessageBox msgBox = QMessageBox(QMessageBox::Information,
                                         "Конец игры",
                                         "Игрок" + gamerName->text() + " победил!",
                                         QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok)
        {
            this->deleteLater();
        }
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
