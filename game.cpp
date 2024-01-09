#include "game.h"

game::game() : d_adventurer{std::make_shared<adventurer>()}, d_monsters{} {
    d_castle.init(d_adventurer, d_monsters);
    d_entrance = d_adventurer->position();
}

int game::mainChoice() const {
    int choice {-1};
    do {
        cout << "Bienvenue dans RiviCastle";
        cout << "(1) JOUER \n";
        cout << "(2) ÉDITER LE CHÂTEAU \n";
        cout << "(3) RÈGLES DU JEU \n";
        cout << "(4) QUITTER \n";
        cout << "Que souhaitez-vous faire ? : ";
        cin >> choice;
    } while(choice < 1 || choice > 4);
    return choice;
}

void game::mainMenu() {
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
        cout << "Vous souhaitez : ";
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
        cout<<"Déplacement souhaité :\n";
        cout<<"(1) ↑ \n";
        cout<<"(2) ↓ \n";
        cout<<"(3) → \n";
        cout<<"(4) ← \n";
        cout<<"(5) ↖ \n";
        cout<<"(6) ↗ \n";
        cout<<"(7) ↙ \n";
        cout<<"(8) ↘ \n";
        cout<<"Votre choix : ";
        cin>>choice;
    } while(choice < 0 || choice > 8);
    return choice;
}

void game::moveAdventurer() {
    int moveA;

    do {
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

        if(newX >= 0 && newY >= 0 && newX < d_castle.d_boxes.size() && newY < d_castle.d_boxes[0].size()) {
            if(d_castle.d_boxes[newX][newY].accessibility()) {
                d_castle.d_boxes[d_adventurer->position().x()][d_adventurer->position().y()].removeCharacter();
                d_adventurer->move(newX, newY);
                d_castle.d_boxes[newX][newY].putCharacter(d_adventurer);
                moveMonsters();
                return;
            }
        }
        cout << "Déplacement impossible";
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

void game::moveMonsters() {
    for(auto &m : d_monsters) {
        m->move(d_castle, d_adventurer, m);
    }
}

void game::end() {
    cout << "À bientôt !";
    std::exit(0);
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
    for (const auto& row : d_castle.d_boxes) {
        for (const auto& box : row) {
            box.show(d);
        }
    }
}
