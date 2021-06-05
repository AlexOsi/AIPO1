#include "Mercenary.h"

int Mercenary::upAttack()  {
    std::cout << "Bow shot!" << std::endl;
    return baseDamage;
}
int Mercenary::middleAttack()  {
    std::cout << "Halberd strike!" << std::endl;

    return baseDamage*getStrength();
}
int Mercenary::downAttack()  {
    if (getDefence() <= 25) {
        std::cout << "Put on piece of fur armor! Plus 5 points to my defence!" << std::endl;
        setDefence(getDefence()+5);
    }
    else {
        std::cout << "Fur armor is fully equipped! Already"
                     + std::to_string(getDefence()) + "points of defence!";
    }
    return 0;
}

int Mercenary::ultimate() {
    std::cout << "Shower of arrows on you!" << std::endl;
    return baseDamage*getStrength()*5;
}