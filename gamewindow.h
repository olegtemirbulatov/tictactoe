#pragma once

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QString>

#include "uigame.h"

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(UIGame *game, QWidget *parent = 0);
    ~GameWindow();

private slots:
    void push_fieldButton();
    void push_exitButton();
    void push_turnButton();

private:
    void clearActiveButtons();

    UIGame *game;
    QPushButton *lastClickedFieldButton;
    QLabel *gamerLabel;
    QLabel *gamerName;
    QHBoxLayout *hlayout1;
    QLabel *turnLabel;
    QLabel *turnNumber;
    QHBoxLayout *hlayout2;
    QGridLayout *field;
    QPushButton *exitButton;
    QPushButton *turnButton;
    QHBoxLayout *hlayout3;
    QVBoxLayout *vlayout;
};
