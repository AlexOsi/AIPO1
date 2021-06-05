#include "Paladin.h"


int Paladin::upAttack()  {
    std::cout << "Ore sword strike!" << std::endl;
    return doubleDamageIfAvailable(baseDamage);
}
int Paladin::middleAttack()  {
    std::cout << "Using magic! Get blinded by glowing light!" << std::endl;
    return doubleDamageIfAvailable(baseDamage * getMagic());
}
int Paladin::downAttack()  {
    std::cout << "Power of king with me! Next 3 attacks with double damage!" << std::endl;
    doubleDamageAttacksAvailable = 3;
    return 0;
}
int Paladin::ultimate()  {
    std::cout << "God heals me! Plus 20 more points to my health!" << std::endl;
    extraHealth = 20;
    return 0;
}
void Paladin::receiveDamage(int damage)  {
    extraHealth -= damage;
    if (extraHealth < 0) {
        damage = extraHealth*(-1);
        extraHealth = 0;
    }
    else {
        damage = 0;
    }
    Hero::receiveDamage(damage);

}

int Paladin::getHealth()  {
    return Hero::getHealth() + extraHealth;
}