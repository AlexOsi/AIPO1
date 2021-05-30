#pragma once

#include <string>
#include <iostream>

class Stats {
public:
    explicit Stats() = default;
    explicit Stats(int health, int defence, int strength, int dexterity, int magic,
                   const std::string &name);

    explicit Stats(int health, int defence, int strength, int dexterity, int magic,
                   std::string &&name);

    ~Stats() = default;

    Stats(const Stats &other) = default;

    Stats(Stats &&other) noexcept = default;

public:
    void setHealth(int health);

    int getHealth() const;

    int getDefence() const;

    int getStrength() const;

    int getDexterity() const;

    int getMagic() const;

    std::string getName() const;

private:
    int m_health = 0, m_defence = 0, m_strength = 0, m_dexterity = 0, m_magic = 0;
    std::string m_name = "";

private:
    const int mainStatsMaxValue = 10;
    const int healthMaxValue = 100;
    std::string messageInvalidArguments = "Invalid stats:\n"
                                          "Defence, strength, dexterity, magic must be less or equal to "
                                          + std::to_string(mainStatsMaxValue)
                                          + "\nHealth must be less or equal to "
                                          + std::to_string(healthMaxValue) + "\n";

    static bool isCorrectStatistic(int statistic, int maxValue) {
        return (statistic >= 0 && statistic <= maxValue);
    }

    bool isArgumentsValid() const;

};