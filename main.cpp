#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Mage.h"
#include "Paladin.h"
#include "Mercenary.h"

enum class Heroes {
    kMage,
    kPaladin,
    kMercenary,
    kUnknown
};

std::shared_ptr<Hero> factoryHero(std::pair<Heroes, std::string> playerData) {
    switch(playerData.first) {
        case Heroes::kMage:
            return std::make_shared<Mage>(std::move(playerData.second));
        case Heroes::kPaladin:
            return std::make_shared<Paladin>(std::move(playerData.second));
        case Heroes::kMercenary:
            return std::make_shared<Mercenary>(std::move(playerData.second));
        default:
            return {};
    }

}

std::pair<Heroes, std::string> inputPlayerData() {
    std::pair<Heroes, std::string> playerData;
    static int playerNum = 1;
    if (playerNum == 1) {
        std::cout << "First player: " << std::endl;
    }
    else if (playerNum == 2) {
        std::cout << "Second player: " << std::endl;
    }
    std::cout << "Choose your Hero: Mage (enter 0), Paladin (enter 1) or Mercenary (enter 2)!" << std::endl;
    int heroNum;
    std::cin >> heroNum;
    playerData.first = static_cast<Heroes>(heroNum);
    std::cout << "What is your name?" << std::endl;
    std::cin >> playerData.second;
    return playerData;
}

void doAttack(std::shared_ptr<Hero>& heroDoingAttack,
                 std::shared_ptr<Hero>& heroReceivingAttack,
                 const Actions currentAttack) {
    if (currentAttack == Actions::kUpAttack) {
        heroReceivingAttack->receiveDamage(heroDoingAttack->upAttack());
    }
    else if (currentAttack == Actions::kMiddleAttack) {
        heroReceivingAttack->receiveDamage(heroDoingAttack->middleAttack());
    }
    else if (currentAttack == Actions::kDownAttack) {
        heroReceivingAttack->receiveDamage(heroDoingAttack->downAttack());
    }

}

bool isAttack(Actions action) {
    if (action == Actions::kDownAttack || action == Actions::kMiddleAttack || action == Actions::kUpAttack) {
        return true;
    }
    return false;
}

void printGameOverMessage(const std::string& winnerName) {
    std::cout << winnerName << " win! " << std::endl;
}

void printRules() {
    std::cout << "Everyone has 3 attacks: up (enter 0), middle (enter 1) and down (enter 2)! "
                 "You can make block and try to guess enemy's action "
                 "To do this, enter 3 and enter enemy's action (0-3)!" << std::endl;
}

void printTurnMessage(const std::string& name, const int health) {
    std::cout << name << "'s turn: " << std::endl;
    std::cout << "HP of your hero: " << health << std::endl;
}

Actions inputAction() {
    int actionNum;
    std::cin >> actionNum;
    return static_cast<Actions>(actionNum);
}

bool isGameOver(std::pair<bool, bool> isPlayersAlive) {
    if (!isPlayersAlive.first || !isPlayersAlive.second) {
        return true;
    }
    return false;
}

std::string getWinnerName(const std::pair<bool, bool> isPlayersAlive,
                          const std::pair<std::string, std::string>& namesPlayers) {
    if (!isPlayersAlive.first) {
        return namesPlayers.second;
    }
    else {
        return namesPlayers.first;
    }
}

int main() {
    /*
     * Нужно задавать тип героя (встроить enum type внутрь класса и выводить название)
     * */
    std::pair<std::pair<Heroes, std::string>,
            std::pair<Heroes, std::string>> playersData{inputPlayerData(), inputPlayerData()}; // Hero type and Name

    std::pair<std::shared_ptr<Hero>,
            std::shared_ptr<Hero>> players {factoryHero(playersData.first), factoryHero(playersData.second)};

    printRules();

    int turn = 0;
    Actions guessAction = Actions::kNone;
    // game
    while (true) {
        if (isGameOver({ players.first->isAlive(), players.second->isAlive() })) {
            std::string winnerName = getWinnerName({players.first->isAlive(), players.second->isAlive()},
                                                   {players.first->getName(), players.second->getName()});
            printGameOverMessage(winnerName);
            break;
        }

        bool isTurnFirstPlayer = (turn % 2 == 0);
        if (isTurnFirstPlayer) {
            printTurnMessage(players.first->getName(), players.first->getHealth());
        } else {
            printTurnMessage(players.second->getName(), players.second->getHealth());
        }

        auto action = inputAction();
        if (isAttack(action)) {
            if (isTurnFirstPlayer) {
                doAttack(players.first, players.second, action);
            } else {
                doAttack(players.second, players.first, action);
            }
        }

        if (guessAction != Actions::kNone) {
            if (action == guessAction) {
                std::cout << "Attack is canceled! Enemy guessed it!" << std::endl;
                if (isTurnFirstPlayer) {
                    players.first->receiveDamage(players.second->ultimate());
                } else {
                    players.second->receiveDamage(players.first->ultimate());
                }
            }
        }
        if (action == Actions::kBlock) {
            int guessActionNum;
            std::cin >> guessActionNum;
            guessAction = static_cast<Actions>(guessActionNum);
        }

        turn++;
    }
    return 0;
}