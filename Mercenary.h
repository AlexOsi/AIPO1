#pragma once
#include "Hero.h"

class Mercenary : public Hero {
public:
    explicit Mercenary(const std::string& name)
            : Hero(Stats{100, 10, 0, 15, 0, name})
    {}
    explicit Mercenary(std::string&& name)
            : Hero(Stats{100, 10, 3, 10, 0, std::move(name)})
    {}
    int upAttack() override;
    int middleAttack() override;
    int downAttack() override;
    int ultimate() override;
private:
    int baseDamage = getDexterity();
};