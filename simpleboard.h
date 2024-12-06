#pragma once

#include <utility>
#include <exception>
#include <stdexcept>
#include <vector>

#include "board.h"


class SimpleBoard : public IBoard
{
public:
    SimpleBoard() = default;
    SimpleBoard(std::size_t N)
    {
        m_size = {N, N};
        m_marks = std::vector<std::vector<Mark>>(N, std::vector<Mark>(N, IBoard::MARK_EMPTY));
    }

    ~SimpleBoard() = default;

    virtual std::pair<PositionType, PositionType> dimension() const override
    {
        IBoard::PositionType pos;
        pos.x = 0;
        pos.y = 0;
        return std::make_pair(pos, m_size);
    }

    virtual Mark getMark(const PositionType &pos) const override
    {
        if (pos.x < m_size.x && pos.y < m_size.y)
            return m_marks[pos.x][pos.y];
        
        throw std::invalid_argument("Invalid position");
        return MARK_UNKNOWN;
    }

    virtual bool setMark(const PositionType &pos, const Mark &mark) override
    {
        if (pos.x < m_size.x && pos.y < m_size.y)
        {
            m_marks[pos.x][pos.y] = mark;
            return true;
        }
        return false;
    }

    virtual std::size_t getDimension()
    {
        return (std::size_t)m_size.x;
    }

private:
    PositionType m_size;
    std::vector<std::vector<Mark>> m_marks;
};
