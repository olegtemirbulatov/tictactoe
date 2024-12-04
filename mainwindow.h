#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QDialog>
#include <QVector>
#include <QString>
#include "gamewindow.h"

bool check_name(QString name);

bool check_number(QString num);

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QString> *gamers = nullptr;
    GameWindow *gameWindow;
};
