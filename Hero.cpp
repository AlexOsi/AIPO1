#include "Hero.h"

void Hero::block(Actions guessAttack, Actions realAttack) {
    if (guessAttack == realAttack) {
        std::cout << "Guess your attack!" << std::endl;
        ultimate();
    }
}

bool Hero::isAlive() const {
    if (m_stats.health <= 0) {
        return false;
    }
    return true;
}

