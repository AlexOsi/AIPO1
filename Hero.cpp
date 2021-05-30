#include "Hero.h"

void Hero::block(int guessAttackNum, int realAttackNum) {
    if (guessAttackNum == realAttackNum) {
        std::cout << "Guess your attack!" << std::endl;
        ultimate();
    }
}

