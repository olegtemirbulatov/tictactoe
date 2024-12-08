#include <QApplication>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <QDebug>
#include <QList>
#include <iostream>

#include "mainwindow.h"
#include "gamewindow.h"
#include "ui_mainwindow.h"

bool check_name(QString name)
{
    return (name.size() > 0);
}

bool check_number(QString num)
{
    bool ok;
    int value = num.toInt(&ok);
    if (!ok)
    {
        return false;
    }
    if ((value < 3) || (value % 2 != 1))
    {
        return false;
    }
    return true;
}

MainWindow::MainWindow(GameManager *_gameManager, QWidget *parent) :
    QMainWindow(parent), gameManager(_gameManager), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dimention->setText("3");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox msgBox = QMessageBox(QMessageBox::Question,
                                     "Подтверждение действия",
                                     "Уверены, что хотите закрыть приложение?",
                                     QMessageBox::Yes|QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    if(ret == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    // Проверка на корректность чисел
    if (!check_number(ui->dimention->text()))
    {
        QMessageBox msgBox = QMessageBox(QMessageBox::Warning,
                                         "Некорректная размерность",
                                         "Введена некорректная размерность поля!");
        msgBox.exec();
    }
    // Проверка на корректность имен
    else if (!check_name(ui->firstPlayerName->text()))
    {
        QMessageBox msgBox = QMessageBox(QMessageBox::Warning,
                                         "Некорректное имя",
                                         "Введено некорректное имя первого игрока!");
        msgBox.exec();
    }
    else if (!check_name(ui->secondPlayerName->text()))
    {
        QMessageBox msgBox = QMessageBox(QMessageBox::Warning,
                                         "Некорректное имя",
                                         "Введено некорректное имя второго игрока!");
        msgBox.exec();
    }
    else
    {
        if (gamers)
            gamers->clear();
        gamers->push_back(std::move(ui->firstPlayerName->text()));
        gamers->push_back(std::move(ui->secondPlayerName->text()));

        IGame *game = gameManager->createGame("UI_game", ui->dimention->text().toInt());
        if (game->waitForPlayers(gamers))
        {
            GameWindow *gameWindow = new GameWindow(game, this);
            gameWindow->exec();
        }
        else
            delete game;
    }
}
