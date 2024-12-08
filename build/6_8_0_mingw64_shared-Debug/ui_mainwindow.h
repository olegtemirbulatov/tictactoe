/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *dimention;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *secondPlayerName;
    QLineEdit *firstPlayerName;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(493, 383);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 471, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName("groupBox");
        QFont font;
        font.setPointSize(15);
        groupBox->setFont(font);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 451, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 451, 31));
        label_2->setFont(font);
        dimention = new QLineEdit(groupBox);
        dimention->setObjectName("dimention");
        dimention->setGeometry(QRect(10, 90, 101, 24));
        dimention->setInputMethodHints(Qt::InputMethodHint::ImhDigitsOnly);

        verticalLayout->addWidget(groupBox);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 150, 471, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        secondPlayerName = new QLineEdit(gridLayoutWidget);
        secondPlayerName->setObjectName("secondPlayerName");
        secondPlayerName->setEnabled(true);
        secondPlayerName->setFont(font);

        gridLayout->addWidget(secondPlayerName, 1, 1, 1, 1);

        firstPlayerName = new QLineEdit(gridLayoutWidget);
        firstPlayerName->setObjectName("firstPlayerName");
        firstPlayerName->setFont(font);

        gridLayout->addWidget(firstPlayerName, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 330, 471, 37));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\270\320\263\321\200\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\260\321\217 \321\200\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\270\320\263\321\200\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\217: 3\321\2053", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200\320\275\320\276\321\201\321\202\321\214 \320\264\320\276\320\273\320\266\320\275\320\260 \320\261\321\213\321\202\321\214 \320\275\320\265\321\207\320\265\321\202\320\275\320\276\320\271!", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\277\320\265\321\200\320\262\320\276\320\263\320\276 \320\270\320\263\321\200\320\276\320\272\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \320\270\320\263\321\200\320\276\320\272\320\260", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\270 \320\262\321\213\320\271\321\202\320\270", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\275\320\276\320\262\321\203\321\216 \320\270\320\263\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
