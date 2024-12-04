#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "simpleboard.h"
#include "consoleplayer.h"
#include "consolegame.h"


ConsoleGame::ConsoleGame(const std::string &name, IBoard* board) : m_name(name)
{
    setup(board);
}

bool ConsoleGame::setup(IBoard* board)
{
    if (m_players.empty())
        m_board.reset(board);
    return true;
}

bool ConsoleGame::waitForPlayers( /*uint64_t timeout*/ ) // аргумент нужен, если мы будем переходить из формата локальной игры к игре по сети
{
    while (m_players.size() < 2)
    {
        std::cout << "Enter name of player " << std::to_string(m_players.size()+1) << std::endl;

        std::string name;
        std::cin >> name;
        if (name.empty())
            continue;
        
        m_players.emplace_back(new ConsolePlayer(name));
    }

    return true;
}

void ConsoleGame::renderBoard() const
{
    // отображение игрового поля
    auto dimension = m_board->dimension();
    const auto &xmin = dimension.first.x;
    const auto &ymin = dimension.first.y;
    const auto &xmax = dimension.second.x;
    const auto &ymax = dimension.second.y;
    
    for (int y = ymin; y < ymax; ++y)
    {
        std::cout << '|';
        for (int x = xmin; x < xmax; ++x)
        {
            IBoard::PositionType pos;
            pos.x = x;
            pos.y = y;
            auto currentMark = m_board->getMark(pos);
            char outSymbol = '_';
            switch (currentMark)
            {
                case IBoard::MARK_O:
                    outSymbol = 'O';
                    break;
                case IBoard::MARK_X:
                    outSymbol = 'X';
                    break;
                default:
                    break;
            }
            std::cout << outSymbol << '|';
        }
        std::cout << std::endl;
    }
}

bool ConsoleGame::ifPlayerWin()
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
    if (std::adjacent_find(marks.begin(),
                           marks.end(),
                           std::not_equal_to<IBoard::Mark>(IBoard::Mark::MARK_EMPTY)) == marks.end())
        return true;
    // if (marks[0] == marks[1] && marks[1] == marks[2] && marks[0] != IBoard::Mark::MARK_EMPTY)
    //     return true;
    marks.clear();

    // проверить побочную диагональ
    for (int x = xmin; x < xmax; ++x)
    {
        pos.x = x;
        pos.y = 2 - x;
        auto currentMark = m_board->getMark(pos);
        marks[x] = currentMark;
    }
    if (std::adjacent_find(marks.begin(),
                           marks.end(),
                           std::not_equal_to<IBoard::Mark>(IBoard::Mark::MARK_EMPTY)) == marks.end())
        return true;
    // if (marks[0] == marks[1] && marks[1] == marks[2] && marks[0] != IBoard::Mark::MARK_EMPTY)
    //     return true;
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
        if (std::adjacent_find(marks.begin(),
                               marks.end(),
                               std::not_equal_to<IBoard::Mark>(IBoard::Mark::MARK_EMPTY)) == marks.end())
            return true;
        // if (marks[0] == marks[1] && marks[1] == marks[2] && marks[0] != IBoard::Mark::MARK_EMPTY)
        //     return true;
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
        if (std::adjacent_find(marks.begin(),
                               marks.end(),
                               std::not_equal_to<IBoard::Mark>(IBoard::Mark::MARK_EMPTY)) == marks.end())
            return true;
        // if (marks[0] == marks[1] && marks[1] == marks[2] && marks[0] != IBoard::Mark::MARK_EMPTY)
        //     return true;
        marks.clear();
    }

    return false;
}

int ConsoleGame::exec()
{
    int iplayer = 0;
    while (true)
    {
        renderBoard();
        auto &player = m_players[iplayer];
        bool moveAccepted = false;
        while (!moveAccepted)
        {
            auto move = player->getMove();
            if (!move)
                return -1;
            
            auto currentMark = m_board->getMark(move.value());
            if (currentMark == IBoard::MARK_EMPTY)
            {
                IBoard::Mark mark;
                if (iplayer == 0) mark = IBoard::MARK_X;
                else if (iplayer == 1) mark = IBoard::MARK_O;
                moveAccepted = m_board->setMark(move.value(), mark);
            }
        }

        if (ifPlayerWin())
        {
            renderBoard();
            std::cout << "Player " << m_players[iplayer].get()->name() << " win!" << std::endl;
            return iplayer;
        }

        iplayer = (iplayer + 1) % 2;
    }

    return -1;
}
