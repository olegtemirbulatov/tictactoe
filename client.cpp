#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <utility>
#include <memory>
#include <QApplication>

#include "mainwindow.h"
#include "board.h"
#include "player.h"
#include "game.h"
#include "gamemanager.h"

int main(int argc, char* argv[])
{
    GameManager gameManager;
    QApplication a(argc, argv);
    MainWindow w(&gameManager);
    w.show();
    return a.exec();
}
