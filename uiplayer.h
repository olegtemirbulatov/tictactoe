#pragma once

#include "player.h"
#include <QString>

class UIPlayer : public IPlayer
{
public:
    UIPlayer() = default;
    UIPlayer(const QString &name) : m_name(name) {}
    ~UIPlayer() = default;

    virtual QString name() const override;

private:
    QString m_name;
};
