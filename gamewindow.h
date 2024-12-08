#pragma once

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QString>
#include <QScrollArea>
#include <memory>

#include "uigame.h"

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(IGame *game, QWidget *parent = 0);
    ~GameWindow();

private slots:
    void push_fieldButton();
    void push_exitButton();
    void push_turnButton();

private:
    void clearActiveButtons();

    IGame *game;
    QVector<QString> *gamers;
    QPushButton *lastClickedFieldButton = nullptr;
    QLabel *gamerLabel;
    QLabel *gamerName;
    QHBoxLayout *hlayout1;
    QLabel *turnLabel;
    QLabel *turnNumber;
    QHBoxLayout *hlayout2;
    QScrollArea *scrollarea;
    QGridLayout *field;
    QPushButton *exitButton;
    QPushButton *turnButton;
    QHBoxLayout *hlayout3;
    QVBoxLayout *vlayout;
};
