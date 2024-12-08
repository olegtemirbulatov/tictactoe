#pragma once

#include <string>
#include <QVector>
#include <QString>

#include "board.h"

class IGame
{
public:
    virtual ~IGame() = default;
    virtual std::string name() const { return ""; }
    virtual bool setup(IBoard* board) = 0;
    virtual bool waitForPlayers(const QVector<QString> *gamers) = 0;
    virtual int exec() = 0;
    virtual QString getPlayer(const int playerNum) const = 0;
    virtual std::size_t getDimension() const = 0;
    virtual bool setMark(const IBoard::PositionType &pos, const IBoard::Mark &mark) = 0;
    virtual bool ifPlayerWin() = 0;
};
