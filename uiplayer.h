#pragma once

#include <QString>

#include "player.h"

class UIPlayer : public IPlayer
{
public:
    UIPlayer();
    UIPlayer(const QString &name) : m_name(name) {}
    ~UIPlayer() = default;

    virtual QString name() const override;
    virtual std::optional<IBoard::PositionType> getMove() const { return IBoard::PositionType{0, 0}; }

private:
    QString m_name;
};
