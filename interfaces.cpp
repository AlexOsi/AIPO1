#include <iostream>
#include <string>
#include <vector>
//interfaces

//static_cast
//dynamic_cast RTTI

class DragonSlayer {
public:
    virtual int strikeDragon() = 0;
};

class Technique {
public:
    Technique()=default;
    virtual ~Technique() = default;
};


//Abstract class
class Hero {
public:
    Hero(std::string name, int hp, int def, int att)
        : m_name(name), m_hp(hp), m_def(def), m_att(att)
    {}

    //virtual void attackToFly() = 0;

    virtual void run() {
        std::cout <<"run" << std::endl;
    }

    virtual void setHp(int att){
        att-=m_def;
        m_hp-=att;

        if(m_hp <= 0) {
            std::cout << "dead"<<std::endl;
        }
    }

private:
    std::string m_name;
    int m_hp, m_def, m_att;
};

void GoToDungeon(Hero* hero)
//Hero&
//std::shared_ptr<Hero>
{
    hero->run(); //<- switch what a hero?!
    hero->setHp(10);
    hero->setHp(200);
}

void GoToDragon(DragonSlayer* slayer){
    if(slayer->strikeDragon() > 5)
        std::cout<<"dragon defeat"<<std::endl;
    else
        std::cout<<"slayer defeat"<<std::endl;
}

//-------------------------------------------------------------------------


class Balista : public Technique, public DragonSlayer {
public:
    int strikeDragon() override {
        std::cout<<"No chance"<<std::endl;
        return 1000;
    }
};

//###HERO###KNIGHT
class Knight : public Hero {
public:
    explicit  Knight(std::string name="Artur", int hp=100, int def=5, int att=5, int shield=10)
        : Hero(name, hp, def, att), m_shield(shield)
    {}

    void setHp(int att){
        att-=m_shield;
        Hero::setHp(att);
    }

private:
    //Hero obj
    int m_shield;
};

class Archer : public Hero, public DragonSlayer {
public:
    explicit  Archer(std::string name="Artur", int hp=100, int def=5, int att=5, int bow=10)
        : Hero(name, hp, def, att), m_bow(bow)
    {}

    void run() override {
        std::cout <<"run wowow new run" << m_bow  << std::endl;
    }

    int strikeDragon()override {
        std::cout<<"strike!"<<std::endl;
        return m_bow;
    }

private:
    int m_bow;
};


/*
template<typename T>
void GoToDungeon(T& hero) {
    hero.Run();
    hero.setHp(10);
    hero.setHp(200);
}*/

Hero* factory(int variant) {
    if(variant==0){
        return new Knight{};
    }
    else {
        return new Archer{};
    }
}


//abstractions (business rules, core logic, ... )
//  ^
//  |
//specific (changable)

//best - no code (interface)
//middle - abstraction
//bad - specific


int min(int x, int y){
    if(x < y)
        return x;
    return y;
}

int max(int x, int y){
    if(x > y)
        return x;
    return y;
}


int main() {
    int variant;
    std::cin >> variant;

    Hero* h = factory(variant);

    //polymorfism <=> if / switch

    std::vector<DragonSlayer*> party;

    Technique* t = new Balista{};
    DragonSlayer* slayer = dynamic_cast<DragonSlayer*>(t);
    if(slayer!= nullptr) {
        party.push_back(slayer);
    }

    DragonSlayer* slayer2 = dynamic_cast<DragonSlayer*>(h);
    if(slayer2!= nullptr) {
        party.push_back(slayer2);
    }

    for(auto s : party ) {
        GoToDragon(s);
    }

    GoToDungeon(h);

    int (*p)(int, int) = nullptr;
    //p = min;
    p = max;

    std::cout<<std::endl;
    std::cout<< p(1,5)<<std::endl;

    return 0;
}
