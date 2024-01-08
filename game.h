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
    void start();
    void end();
    int moveChoiceAdv() const;
    void moveAdventurer();
    void moveMonsters();
    void showCastle();
    void loop();
private:
    std::shared_ptr<adventurer> d_adventurer;
    vector<std::shared_ptr<monster>> d_monsters;
    castle d_castle;
};


#endif //__CASE_H__