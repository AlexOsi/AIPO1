#pragma once
#include "Stats.h"

class Hero {
public:
    explicit Hero() = default;
    explicit Hero(const Stats& stats)
            : m_stats(stats)
    {}
    explicit Hero(Stats&& stats)
            : m_stats(std::move(stats))
    {}

public:

    virtual int downAttack() = 0;
    virtual int middleAttack() = 0;
    virtual int upAttack() = 0;

    virtual int ultimate() = 0;

    void block(int guessAttackNum, int realAttackNum);

    virtual void receiveDamage(int damage) {
        m_stats.setHealth(damage - m_stats.getDefence());
    }

protected:
    Stats m_stats;


};