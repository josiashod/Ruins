#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <vector>
#include "character.h"
#include "monster.h"
#include "castle.h"
#include <memory>
using std::vector;
using std::cin;
using std::cout;

#define MAIN_MENU "\
########################################################\n\
##             ------ CASTLE GAME ------              ##\n\
##              -------- MENU ---------               ##\n\
##                                                    ##\n\
##             (1) JOUER                              ##\n\
##             (2) ÉDITER LE CHÂTEAU                  ##\n\
##             (3) RÈGLES DU JEU                      ##\n\
##             (4) QUITTER                            ##\n\
##                                                    ##\n\
##                                                    ##\n\
########################################################\n\
"

#define PLAYER_MENU "\
(1): ↑ (2): ↓ (3): → (4): ← (5): ↖ (6): ↗ (7): ↙ (8): ↘ \n\
"

class game {
public:
    game();
    int mainChoice() const;
    void start();
    void rules();
    int moveChoiceAdv() const;
    void loop();
    int gameChoice() const;
    void gameMenu();
    void moveAdventurer();
    void end();
    void showCastle();
    void player_info() const;

    void moveMonsters();
private:
    std::shared_ptr<adventurer> d_adventurer;
    vector<std::shared_ptr<monster>> d_monsters;
    display d;
    castle d_castle;
    coord d_entrance;
};


#endif //__CASE_H__