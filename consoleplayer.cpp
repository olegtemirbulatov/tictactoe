#include <optional>
#include <iostream>

#include "consoleplayer.h"

std::string ConsolePlayer::name() const
{
    return m_name;
}

std::optional<IBoard::PositionType> ConsolePlayer::getMove() const
{
    std::cout << "player " << name() << " enter your move: " << std::endl;
    IBoard::PositionType pos;
    std::cout << "x: ";
    std::cin >> pos.x;
    std::cout << "y: ";
    std::cin >> pos.y;

    return pos;
}