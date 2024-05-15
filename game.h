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
##             (2) CHARGER UN CHÂTEAU                 ##\n\
##             (3) ÉDITER LE CHÂTEAU                  ##\n\
##             (4) RÈGLES DU JEU                      ##\n\
##             (5) QUITTER                            ##\n\
##                                                    ##\n\
##                                                    ##\n\
########################################################\n\
"

#define RULES "\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@                    ------ RÈGLES ------                    @\n\
@                                                            @\n\
@    Le jeu se deroule par tours. Durant chaque tour,        @\n\
@    vous vous deplacez en choisissant une direction         @\n\
@    si vous êtes sur un tas de pieces de monnaie,           @\n\
@    vous les ramassés. Aussi, chaque monstre se deplace,    @\n\
@    à chaque tour, si un monstre se deplace sur vous alors  @\n\
@    il vous attaque. Dans le cas contraire vous l'attaquer  @\n\
@    En vous deplacant sur lui.                              @\n\
@    À chaque attaque recu vos equipements perdent des       @\n\
@    points de solidité.                                     @\n\
@    Une piece d'or repare un point de solidite de l'epee    @\n\
@    ou de l'armure.                                         @\n\
@    Vous gagnez la partie lorsque vous sortez du chateau    @\n\
@    L'amulette.                                             @\n\
@                                                            @\n\
@                        BONNE CHANCE                        @\n\
@                                                            @\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
"

#define LEGEND "\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@            ------ LÉGENDE ------            @\n\
@                                             @\n\
@    W : Mur                                  @\n\
@    E : Case externe                         @\n\
@    C : Pièces (ex. C10 pour 10)             @\n\
@    Attention : Chaque case 'C' doit être    @\n\
@    doit être accompagnée d'un nombre        @\n\
@    représentant les pièces présentes        @\n\
@    sur la case.                             @\n\
@    A : Amulette                             @\n\
@    P : Aventurier (Un seul obligatoire)     @\n\
@    M : Monstre                              @\n\
@    B : Monstre aveugle                      @\n\
@                                             @\n\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
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
    void edit();
    void end(bool res);
    void showCastle();
    // void playerInfo() const;
    void repairSwordOrArmor();
    void updateMonsters();
    void loadMap();
    void close();
    void monsterInfo();

    void moveMonsters();
private:
    std::shared_ptr<adventurer> d_adventurer;
    vector<std::shared_ptr<monster>> d_monsters;
    display d;
    castle d_castle;
    coord d_entrance;
};


#endif //__CASE_H__
