#pragma once
#include "Hero.h"


class Mage : public Hero {
public:
    explicit Mage(const std::string& name)
            : Hero(Stats{100, 5, 0, 0, 15, name})
    {}
    explicit Mage(std::string&& name)
            : Hero(Stats{100, 5, 0, 0, 15, std::move(name)})
    {}

    int upAttack() override;
    int middleAttack() override;
    int downAttack() override;

    int ultimate() override;

    void receiveDamage(int damage) override;



private:
    int baseDamage = getMagic();
    int m_spellPower = 100;
    int m_percentDamageReduction = 0;
};