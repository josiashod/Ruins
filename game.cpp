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

int game::mainChoice() const
{
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
    int d = 0;
    do {
        d = mainChoice();
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
        cout << d;
        d = 0;
    } while(d != 4);
}

int game::gameChoice() const {
    int choice {-1};
    do {
        cout << "(1) VOUS DÉPLACER \n";
        cout << "(2) RÉPARER VOTRE ARMURE OU VOTRE ÉPÉE \n";
        cout << "(3) QUITTER (vous perderez votre avancement) \n";
        cout << "Votre choix : ";
        cin >> choice;
    } while(choice < 1 || choice > 3);
    return choice;
}

void game::gameMenu() {
    int d = gameChoice();
    switch (d) {
        case 1 : moveAdventurer();
            break;
        case 2 : repairSwordOrArmor();
            break;
        case 3 : end();
            break;
    }
}

// !(dead || (amulet && position))
// !dead
void game::loop() {
    while(!d_adventurer->isDead() && !(d_adventurer->amulet() && d_adventurer->position() == d_entrance)) {
        showCastle();
        gameMenu();
    }
    cout << "🎊🎊🎊🎊🎊🎊 Vous avez gagné, félicitations 🎊🎊🎊🎊🎊🎊";
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

    do {
        moveA = moveChoiceAdv();

        int lig = d_adventurer->position().x();
        int col = d_adventurer->position().y();

        switch(moveA) {
            case 1: lig -= 1; break;
            case 2: lig += 1; break;
            case 3: col += 1; break;
            case 4: col -= 1; break;
            case 5: col -= 1; lig -= 1; break;
            case 6: col += 1; lig -= 1; break;
            case 7: col -= 1; lig += 1; break;
            case 8: col += 1; lig += 1; break;
        }

        if(lig >= 0 && col >= 0 && lig < d_castle.d_boxes.size() && col < d_castle.d_boxes[0].size()) {
            if(d_castle.d_boxes[lig][col].accessibility() && d_castle.d_boxes[lig][col].putCharacter(d_adventurer))
            {
                d_castle.d_boxes[d_adventurer->position().x()][d_adventurer->position().y()].removeCharacter();
                d_adventurer->move(lig, col);
                updateMonsters();
                moveMonsters();
                return;
            }
        }
        cout << "Déplacement impossible" << std::endl;
    } while(moveA > 0 && moveA <= 8);
}

void game::repairSwordOrArmor() {
    int coinAmount;
    do {
        cout << "Combien de pièces souhaitez-vous utiliser pour réparer (pour l'épée ou l'armure) ? ";
        cin >> coinAmount;

        if(coinAmount <= 0 || coinAmount > d_adventurer->coins()) {
            cout << "Nombre de pièces invalide. Veuillez saisir un nombre positif et inférieur ou égal à votre solde de pièces." << std::endl;
        }
    } while (coinAmount <= 0 || coinAmount > d_adventurer->coins());

    int choice;
    do {
        cout << "Que voulez-vous réparer ?" << std::endl;
        cout << "(1) L'épée" << std::endl;
        cout << "(2) L'armure" << std::endl;
        cout << "Votre choix : ";
        cin >> choice;
    } while (choice != 1 && choice != 2);

    if(choice == 1) {
        d_adventurer->repairSword(coinAmount);
        cout << "L'épée a bien été réparée.";
    } else {
        d_adventurer->repairArmor(coinAmount);
        cout << "L'armure a bien été réparée.";
    }
}

// Delete the dead monsters
void game::updateMonsters()
{
    int i = 0;
    while(i < d_monsters.size())
    {
        if(d_monsters[i]->isDead())
            d_monsters.erase(d_monsters.begin() + i);
        else
            i++;
    }
}


void game::moveMonsters() {
    for(auto &m : d_monsters)
    {
        m->move(d_castle, d_adventurer, m);
    }
}

void game::end() {
    cout << "À bientôt !" << std::endl;
}

void game::player_info() const
{
    cout << "----- INFO ----" << std::endl;
    cout << "💓 : " << d_adventurer->health() << " 💪 :" << d_adventurer->strength() << std::endl;
    cout << "🪙 : " << d_adventurer->coins() << " 🧿 :" << d_adventurer->amulet() << std::endl;
    cout << "🗡 : " << d_adventurer->coins() << " 🛡 :" << d_adventurer->amulet() << std::endl;

    // 🗡 🪙 🧿 🛡
}

void game::rules() {
    clrscr();
    char choice;
    // cout << ":\n";
    // cout << "- l'utilisateur deplace l'aventurier; si l'aventurier est sur un tas de pieces de monnaie, il les ramasse.\n";
    // cout << "- chaque monstre se deplace; si un monstre se deplace sur l'aventurier alors il l'attaque.\n";
    // cout << "- le joueur peut choisir de reparer son equipement avec des pieces d'or.\n";
    // cout << "  - Une piece d'or repare un point de solidite de l'epee ou de l'armure.\n";
    // cout << "  - L'epee perd un point de solidite a chaque attaque.\n";
    // cout << "  - L'armure perd des points de solidite lors d'attaques de monstres.\n";
    // cout << "  - Les points repares sont pris a partir des pieces d'or dans la bourse de l'aventurier.\n";
    // cout << "- le jeu se termine soit quand l'aventurier est mort, soit quand il est a la sortie du chateau avec l'amulette.\n";
    cout << RULES;
    cout << "Continuer (c) >> ";
    cin >> choice;
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
