#include "Hero.h"
#include <iostream>
#include <vector>
#include <string>
#include <exception>

enum class Attacks {
    kDownAttack,
    kMiddleAttack,
    kUpAttack
};

class Mage : public Hero {
public:
    explicit Mage() = default;
    explicit Mage(const Stats& stats)
        : Hero(stats)
    {}
    explicit Mage(Stats&& stats)
        : Hero(std::move(stats))
    {}

    int upAttack() override {
        std::cout << "Throw fireball!" << std::endl;
        return baseDamage;
    }
    int middleAttack() override {
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
    int downAttack() override {

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

    int ultimate() override {
        std::cout << "Destroy you with fiery rain!" << std::endl;
        return baseDamage * 5;
    }

    void receiveDamage(int damage) override {
        if (m_percentDamageReduction != 0) {
            damage -= static_cast<int>(m_percentDamageReduction * 0.01 * damage);
        }
        Hero::receiveDamage(damage);
    }

private:
    int baseDamage = m_stats.getMagic();
    int m_spellPower = 100;
    int m_percentDamageReduction = 0;
};

class Paladin : public Hero {
public:
    explicit Paladin() = default;
    explicit Paladin(const Stats& stats)
        : Hero(stats)
    {}
    explicit Paladin(Stats&& stats)
        : Hero(std::move(stats))
    {}
    int upAttack() override {
        std::cout << "Ore sword strike!" << std::endl;
        int damage;
        if (countDoubleDamage != 0) {
            damage = baseDamage * 2;
            countDoubleDamage--;
            std::cout << "Double damage!" << std::endl;
        }
        else {
            damage = baseDamage;
        }
        return damage;
    }
    int middleAttack() override {
        std::cout << "Using magic! Get blinded by glowing light!" << std::endl;
        return baseDamage*m_stats.getMagic();
    }
    int downAttack() override {
        std::cout << "Power of king with me! Next 3 attacks with double damage!" << std::endl;
        countDoubleDamage = 3;
        return 0;
    }
    int ultimate() override {
        std::cout << "God heals me! Plus 50 more points to my health!" << std::endl;
        std::cout << m_stats.getHealth() << std::endl;
        int newHealth = m_stats.getHealth() + 30;
        if (newHealth > 100) {
            newHealth = 100;
        }
        m_stats.setHealth(newHealth);
        std::cout << m_stats.getHealth() << std::endl;
        return 0;
    }


private:
    int baseDamage = m_stats.getStrength();
    int countDoubleDamage = 0;
};

int main() {
    Paladin A;
    try {
        Stats stats{50,5,5,4,5,"s"};
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
    }

    return 0;
}
