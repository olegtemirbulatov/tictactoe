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
    UIGame(IBoard *board);
    ~UIGame() = default;

    virtual bool setup(IBoard* board) override;
    virtual bool waitForPlayers(QVector<QString> *gamersList) override;
    virtual int exec(/* add parameters */) override { return 0; }
    virtual bool ifPlayerWin() override;
    virtual QString getPlayer(int playerNum) override;
    virtual std::size_t getDimension() override;
    virtual bool setMark(const IBoard::PositionType &pos, const IBoard::Mark &mark) override;

private:
    std::unique_ptr<IBoard> m_board;
    std::vector<std::unique_ptr<IPlayer>> m_players;
};
