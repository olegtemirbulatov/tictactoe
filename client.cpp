// при доработке UI нужно дорабатывать по большей части этот файл
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <utility>
#include <memory>
#include "mainwindow.h"
#include <QApplication>


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
