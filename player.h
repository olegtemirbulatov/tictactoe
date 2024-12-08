#pragma once

#include <string>
#include <optional>
#include <QString>

#include "board.h"

class IPlayer
{
public:
    IPlayer() = default;
    virtual ~IPlayer() = default;
    virtual QString name() const = 0;
    virtual std::optional<IBoard::PositionType> getMove() const = 0;
};

