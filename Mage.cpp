#include "Mage.h"

int Mage::upAttack() {
    std::cout << "Throw fireball!" << std::endl;
    return baseDamage;
}
int Mage::middleAttack() {
    int damage;
    if (m_spellPower == 0) {
        damage = baseDamage;
        std::cout << "Spell power is over!" << std::endl;
    }
    else {
        damage = baseDamage + 10;
        std::cout << "Adding 10 spell power to attack!" << std::endl;
        m_spellPower -= 10;
    }
    return damage;
}
int Mage::downAttack() {

    if (m_percentDamageReduction < 75) {
        m_percentDamageReduction += 25;
        std::cout << "Spell: fire shield! Not getting " << m_percentDamageReduction
                  << " % of your attack!" << std::endl;
    }
    else {
        std::cout << "Already not getting 75% of attack from the fire shield!" << std::endl;
    }
    return 0;
}

int Mage::ultimate() {
    std::cout << "Destroy you with fiery rain!" << std::endl;
    return baseDamage * 5;
}

void Mage::receiveDamage(int damage) {
    if (m_percentDamageReduction != 0) {
        damage -= static_cast<int>(m_percentDamageReduction * 0.01 * damage);
    }
    Hero::receiveDamage(damage);
}
