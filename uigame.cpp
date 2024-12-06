#include "uigame.h"
#include "ui_mainwindow.h"
#include "uiplayer.h"
#include <algorithm>

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

    std::vector<IBoard::Mark> marks(xmax);
    IBoard::PositionType pos;

    // проверить главную диагональ
    for (int x = xmin; x < xmax; ++x)
    {
        pos.x = x;
        pos.y = x;
        auto currentMark = m_board->getMark(pos);
        marks[x] = currentMark;
    }
    if (std::equal(marks.begin()+1, marks.end(), marks.begin()) && marks[0] != IBoard::Mark::MARK_EMPTY)
        return true;
    marks.clear();

    // проверить побочную диагональ
    for (int x = xmin; x < xmax; ++x)
    {
        pos.x = x;
        pos.y = xmax - x - 1;
        auto currentMark = m_board->getMark(pos);
        marks[x] = currentMark;
    }
    if (std::equal(marks.begin()+1, marks.end(), marks.begin()) && marks[0] != IBoard::Mark::MARK_EMPTY)
        return true;
    marks.clear();

    // проверить по горизонталям
    for (int y = ymin; y < ymax; ++y)
    {
        for (int x = xmin; x < xmax; ++x)
        {
            pos.x = x;
            pos.y = y;
            auto currentMark = m_board->getMark(pos);
            marks[x] = currentMark;
        }
        if (std::equal(marks.begin()+1, marks.end(), marks.begin()) && marks[0] != IBoard::Mark::MARK_EMPTY)
            return true;
        marks.clear();
    }

    // проверить по вертикалям
    for (int x = xmin; x < xmax; ++x)
    {
        for (int y = ymin; y < ymax; ++y)
        {
            pos.x = x;
            pos.y = y;
            auto currentMark = m_board->getMark(pos);
            marks[y] = currentMark;
        }
        if (std::equal(marks.begin()+1, marks.end(), marks.begin()) && marks[0] != IBoard::Mark::MARK_EMPTY)
            return true;
        marks.clear();
    }

    return false;
}

bool UIGame::waitForPlayers(QVector<QString> *gamersList)
{
    if (gamersList->size() == 2)
    {
        for (int i = 0; i < 2; ++i)
        {
            m_players.emplace_back(new UIPlayer(gamersList->at(i)));
        }
        return true;
    }

    return false;
}

QString UIGame::getPlayer(int playerNum)
{
    return m_players[playerNum]->name();
}

std::size_t UIGame::getDimension()
{
    return m_board->getDimension();
}

bool UIGame::setMark(const IBoard::PositionType &pos, const IBoard::Mark &mark)
{
    return m_board->setMark(pos, mark);
}
