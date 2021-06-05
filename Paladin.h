#pragma once
#include "Hero.h"

class Paladin : public Hero {
public:
    explicit Paladin(const std::string& name)
            : Hero(Stats{100, 15, 10, 0, 3, name})
    {}
    explicit Paladin(std::string&& name)
            : Hero(Stats{100, 15, 10, 0, 3, std::move(name)})
    {}
    int upAttack() override;
    int middleAttack() override;
    int downAttack() override;
    int ultimate() override;
    void receiveDamage(int damage) override;

    int getHealth() override;
private:
    int baseDamage = getStrength();
    int extraHealth = 0;
    int doubleDamageAttacksAvailable = 0;
    int doubleDamageIfAvailable(int damage) {
        if (doubleDamageAttacksAvailable != 0) {
            damage = damage * 2;
            doubleDamageAttacksAvailable--;
            std::cout << "Double damage!" << std::endl;
        }
        return damage;
    }
};