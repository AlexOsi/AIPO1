#include "Stats.h"

Stats::Stats(int health, int defence, int strength, int dexterity, int magic,
             const std::string &name)
        : m_health(health), m_defence(defence), m_strength(strength), m_dexterity(dexterity),
          m_magic(magic), m_name(name) {
    if (!isArgumentsValid()) {
        throw std::invalid_argument(messageInvalidArguments);
    }
}

Stats::Stats(int health, int defence, int strength, int dexterity, int magic,
             std::string &&name)
        : m_health(health), m_defence(defence), m_strength(strength), m_dexterity(dexterity),
          m_magic(magic), m_name(std::move(name)) {
    if (!isArgumentsValid()) {
        throw std::invalid_argument(messageInvalidArguments);
    }
}

void Stats::setHealth(int health) {
    if (health <= 0) {
        m_health = 0;
    } else if (health >= 100) {
        m_health = 100;
    } else {
        m_health = health;
    }
}

int Stats::getHealth() const {
    return m_health;
}

int Stats::getDefence() const {
    return m_defence;
}

int Stats::getStrength() const {
    return m_strength;
}

int Stats::getDexterity() const {
    return m_dexterity;
}

int Stats::getMagic() const {
    return m_magic;
}

std::string Stats::getName() const {
    return m_name;
}


bool Stats::isArgumentsValid() const {
    return (isCorrectStatistic(m_strength, mainStatsMaxValue)
            && isCorrectStatistic(m_magic, mainStatsMaxValue)
            && isCorrectStatistic(m_defence, mainStatsMaxValue)
            && isCorrectStatistic(m_dexterity, mainStatsMaxValue)
            && isCorrectStatistic(m_health, healthMaxValue));
}
