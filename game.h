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

class game {
public:
    game();
    int mainChoice() const;
    void mainMenu();
    void rules();
    int moveChoiceAdv() const;
    void loop();
    int gameChoice() const;
    void gameMenu();
    void moveAdventurer();
    void end();
    void showCastle();

    void moveMonsters();
private:
    std::shared_ptr<adventurer> d_adventurer;
    vector<std::shared_ptr<monster>> d_monsters;
    display d;
    castle d_castle;
    coord d_entrance;
};


#endif //__CASE_H__