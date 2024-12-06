#pragma once

#include "player.h"
#include <QString>

class UIPlayer : public IPlayer
{
public:
    UIPlayer();
    UIPlayer(const QString &name) : m_name(name) {}
    ~UIPlayer() = default;

    virtual QString name() const override;
    virtual std::optional<IBoard::PositionType> getMove() const {}

private:
    QString m_name;
};
