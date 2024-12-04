QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    gamewindow.cpp \
    mainwindow.cpp \
    uigame.cpp \
    consolegame.cpp \
    consoleplayer.cpp \
    gamemanager.cpp \
    simpleboard.cpp \
    uigame.cpp \
    uiplayer.cpp

HEADERS += \
    gamewindow.h \
    mainwindow.h \
    uigame.h \
    board.h \
    consolegame.h \
    consoleplayer.h \
    game.h \
    gamemanager.h \
    player.h \
    simpleboard.h \
    uigame.h \
    uiplayer.h

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
