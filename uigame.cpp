#include <algorithm>

#include "uigame.h"
#include "ui_mainwindow.h"
#include "uiplayer.h"

UIGame::UIGame(IBoard* board)
{
    setup(board);
}

bool UIGame::setup(IBoard *board)
{
    if (m_players.empty())
        m_board.reset(board);
    return true;
}

bool UIGame::ifPlayerWin()
{
    auto dimension = m_board->dimension();
    const auto &xmin = dimension.first.x;
    const auto &ymin = dimension.first.y;
    const auto &xmax = dimension.second.x;
    const auto &ymax = dimension.second.y;

    std::vector<IBoard::Mark> marks;
    IBoard::PositionType pos;

    // проверить главную диагональ
    for (unsigned x = xmin; x < xmax; ++x)
    {
        pos.x = x;
        pos.y = x;
        auto currentMark = m_board->getMark(pos);
        marks.push_back(currentMark);
    }
    if (std::equal(marks.begin()+1, marks.end(), marks.begin())
        && marks[0] != IBoard::Mark::MARK_EMPTY)
        return true;
    marks.clear();

    // проверить побочную диагональ
    for (unsigned x = xmin; x < xmax; ++x)
    {
        pos.x = x;
        pos.y = xmax - x - 1;
        auto currentMark = m_board->getMark(pos);
        marks.push_back(currentMark);
    }
    if (std::equal(marks.begin()+1, marks.end(), marks.begin())
        && marks[0] != IBoard::Mark::MARK_EMPTY)
        return true;
    marks.clear();

    // проверить по горизонталям
    for (unsigned y = ymin; y < ymax; ++y)
    {
        for (unsigned x = xmin; x < xmax; ++x)
        {
            pos.x = x;
            pos.y = y;
            auto currentMark = m_board->getMark(pos);
            marks.push_back(currentMark);
        }
        if (std::equal(marks.begin()+1, marks.end(), marks.begin())
            && marks[0] != IBoard::Mark::MARK_EMPTY)
            return true;
        marks.clear();
    }

    // проверить по вертикалям
    for (unsigned x = xmin; x < xmax; ++x)
    {
        for (unsigned y = ymin; y < ymax; ++y)
        {
            pos.x = x;
            pos.y = y;
            auto currentMark = m_board->getMark(pos);
            marks.push_back(currentMark);
        }
        if (std::equal(marks.begin()+1, marks.end(), marks.begin())
            && marks[0] != IBoard::Mark::MARK_EMPTY)
            return true;
        marks.clear();
    }

    return false;
}

bool UIGame::waitForPlayers(const QVector<QString> *gamersList)
{
    for (int i = 0; i < 2; ++i)
    {
        m_players.emplace_back(new UIPlayer(gamersList->at(i)));
    }
    return true;
}

QString UIGame::getPlayer(const int playerNum) const
{
    return m_players[playerNum]->name();
}

std::size_t UIGame::getDimension() const
{
    return m_board->getDimension();
}

bool UIGame::setMark(const IBoard::PositionType &pos, const IBoard::Mark &mark)
{
    return m_board->setMark(pos, mark);
}
