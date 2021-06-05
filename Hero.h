#pragma once
#include "Stats.h"
#include <iostream>

enum class Actions {
    kDownAttack, // 0
    kMiddleAttack, // 1
    kUpAttack, // 2
    kBlock, // 3
    kNone
};

class Hero {
public:
    explicit Hero(const Stats& stats)
            : m_stats(stats)
    {}
    explicit Hero(Stats&& stats)
            : m_stats(std::move(stats))
    {}

public:
    bool isAlive() const;

    int getMagic() {
        return m_stats.magic;
    }
    int getDefence() {
        return m_stats.defence;
    }
    virtual int getHealth() {
        return m_stats.health;
    }
    int getStrength() {
        return m_stats.strength;
    }
    int getDexterity() {
        return m_stats.dexterity;
    }
    void setDefence(int defence) {
        if (defence >= 0 && defence <= 100) {
            m_stats.defence = defence;
        }
    }
    std::string getName() {
        return m_stats.name;
    }
    virtual int downAttack() = 0;
    virtual int middleAttack() = 0;
    virtual int upAttack() = 0;



    virtual void receiveDamage(int damage) {
        m_stats.health -= damage - m_stats.defence;
    }

    void block(Actions guessAttack, Actions realAttack);

//protected:
    virtual int ultimate() = 0;
private:
    Stats m_stats;
};