#pragma once

#include <vector>
#include <utility>
#include <memory>
#include <QVector>
#include <QString>

#include "player.h"
#include "board.h"
#include "game.h"

class UIGame : public IGame
{
public:
    UIGame(IBoard *board) = default;
    UIGame(IBoard *board);
    ~UIGame() = default;

    virtual bool setup(IBoard* board) override;
    virtual bool waitForPlayers(QVector<QString> *gamersList) override {}
    virtual int exec(/* add parameters */) override {}
    bool ifPlayerWin();
    QString getPlayer(int playerNum);
    std::size_t getDimension();
    bool setMark(const IBoard::PositionType &pos, const IBoard::Mark &mark);

private:
    std::unique_ptr<IBoard> m_board;
    std::vector<std::unique_ptr<IPlayer>> m_players;
};
