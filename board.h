#pragma once

#include <utility>

class IBoard
{
public:
    struct PositionType
    {
        typedef unsigned Dimension;
        Dimension x = 0;
        Dimension y = 0;
    };

    enum Mark : unsigned char
    {
        MARK_UNKNOWN = 0xff,
        MARK_EMPTY = 0,
        MARK_O,
        MARK_X
    };

    virtual ~IBoard() = default;

    virtual std::pair<PositionType, PositionType> dimension() const
    {
        // возвр размер поля
        return std::pair<PositionType, PositionType> {};
    }

    virtual Mark getMark(const PositionType &pos) const
    {
        return MARK_UNKNOWN; 
    }

    virtual bool setMark(const PositionType &pos, const Mark &mark)
    { 
        return false; 
    }

    virtual std::size_t getDimension() = 0;
};
