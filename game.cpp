#include "game.h"
#include <stdlib.h>

/**
 * @brief Clear console
 * 
 */
void clrscr()
{
    #ifdef _WIN32
	    system("cls");
	#elif __unix__
	    system("clear");
	#endif
}

game::game() : d_adventurer{std::make_shared<adventurer>()}, d_monsters{} {
    d_castle.init(d_adventurer, d_monsters);
    d_entrance = d_adventurer->position();
}

int game::mainChoice() const {
    clrscr();
    int choice {-1};
    do {
        cout << MAIN_MENU;
        cout << ">> ";
        cin >> choice;
    } while(choice < 1 || choice > 4);
    return choice;
}

void game::start() {
    int d = mainChoice();
    switch (d) {
        case 1 : loop();
            break;
        // case 2 : d_castle.edit(); d = mainChoice();
            // break;
        case 3 : rules();
            break;
        case 4 : end();
            break;
    }
}

int game::gameChoice() const {
    int choice {-1};
    do {
        cout << "(1) VOUS DÉPLACER \n";
        cout << "(2) RÉPARER VOTRE ARMURE \n";
        cout << "(3) RÉPARER VOTRE ÉPÉE \n";
        cout << "(4) QUITTER (vous perderez votre avancement) \n";
        cout << "Votre choix : ";
        cin >> choice;
    } while(choice < 1 || choice > 4);
    return choice;
}

void game::gameMenu() {
    int d = gameChoice();
    switch (d) {
        case 1 : moveAdventurer();
            break;
        // case 2 : d_adventurer->repareArmor();
            // break;
        // case 3 : d_adventurer->repareSword();
            // break;
        case 4 : end();
            break;
    }
}

void game::loop() {
    while(!d_adventurer->isDead() || (d_adventurer->amulet() && d_adventurer->position() != d_entrance)) {
        showCastle();
        gameMenu();
    }
    cout << "Vous avez gagné, félicitations !";
    end();
}

int game::moveChoiceAdv() const
{
    int choice {-1};
    do {
        cout << PLAYER_MENU;
        cout << ">> ";
        cin >> choice;
    } while(choice < 0 || choice > 8);
    return choice;
}

void game::moveAdventurer() {
    int moveA;

    // do {
    moveA = moveChoiceAdv();

    int newX = d_adventurer->position().x();
    int newY = d_adventurer->position().y();

    switch(moveA) {
        case 1: newY += 1; break;
        case 2: newY -= 1; break;
        case 3: newX += 1; break;
        case 4: newX -= 1; break;
        case 5: newX -= 1; newY += 1; break;
        case 6: newX += 1; newY += 1; break;
        case 7: newX -= 1; newY -= 1; break;
        case 8: newX += 1; newY -= 1; break;
    }

    if(newX >= 0 && newY >= 0 && newY < d_castle.d_boxes.size() && newX < d_castle.d_boxes[0].size()) {
        if(d_castle.d_boxes[newX][newY].accessibility()) {
            cout << newX;
            d_castle.d_boxes[d_adventurer->position().x()][d_adventurer->position().y()].removeCharacter();
            d_adventurer->move(newX, newY);
            d_castle.d_boxes[newX][newY].putCharacter(d_adventurer);
            moveMonsters();
            // cout << "call";
            return;
        }
    }
        // cout << "Déplacement impossible";
    // } while(moveA > 0 && moveA <= 8);
}

void game::moveMonsters() {
    for(auto &m : d_monsters) {
        m->move(d_castle, d_adventurer, m);
    }
}

void game::end() {
    cout << "À bientôt !";
    std::exit(0);
}

void game::player_info() const
{
    cout << "💓 : " << d_adventurer->health() << " 💪 :" << d_adventurer->strength() << std::endl;
    cout << "🪙 : " << d_adventurer->coins() << " 🧿 :" << d_adventurer->amulet() << std::endl;
    cout << "🗡 : " << d_adventurer->coins() << " 🛡 :" << d_adventurer->amulet() << std::endl;

    // 🗡 🪙 🧿 🛡
}

void game::rules() {
    cout << "Le jeu se deroule par tours. A chaque tour:\n";
    cout << "- l'utilisateur deplace l'aventurier; si l'aventurier est sur un tas de pieces de monnaie, il les ramasse.\n";
    cout << "- chaque monstre se deplace; si un monstre se deplace sur l'aventurier alors il l'attaque.\n";
    cout << "- le joueur peut choisir de reparer son equipement avec des pieces d'or.\n";
    cout << "  - Une piece d'or repare un point de solidite de l'epee ou de l'armure.\n";
    cout << "  - L'epee perd un point de solidite a chaque attaque.\n";
    cout << "  - L'armure perd des points de solidite lors d'attaques de monstres.\n";
    cout << "  - Les points repares sont pris a partir des pieces d'or dans la bourse de l'aventurier.\n";
    cout << "- le jeu se termine soit quand l'aventurier est mort, soit quand il est a la sortie du chateau avec l'amulette.\n";
}

void game::showCastle() {
    clrscr();
    int width = d_castle.d_boxes[0].size();

    for(int i = 0; i < width; ++i)
        cout << "+---";
    cout << "+ ";

    for (const auto& row : d_castle.d_boxes) {
        cout << std::endl;
        cout << "+";
        for (const auto& box : row) {
            cout << "  ";
            box.show(d);
            cout << " ";
        }
        cout << " +";
        cout << std::endl;
    }
    cout << " ";
    for(int i = 0; i < width; ++i)
        cout << "+---";
    cout << '+' << std::endl;
    player_info();
}
