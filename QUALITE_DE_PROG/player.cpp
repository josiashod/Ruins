//
// Created by Daav on 18/11/2023.
//

#include <cstdlib>
#include "player.h"
using std::cout, std::cin;

player::player() : character{'A', "Aventurier"}, d_coins{1}, d_sword{}, d_armor{} {}

int player::coins() const {
    // Renvoi du nombre de pièces
    return d_coins;
}

void player::attack(character &c) const {
    // Initialisation de la force d'attaque
    int attackStrength = d_strengthPoints + d_sword.solidityPoints();

    // Génération d'un nombre aléatoire entre 0 et 99 et vérification de l'infériorité de ce nombre à 80
    if ((rand() % 100) < 80)
        // Si la probabilité générée est inférieure à 80, on multiplie la force d'attaque par 0,9
        attackStrength = static_cast<int>(attackStrength * 0.9);

    // Lancement de l'attaque sur le personnage c
    c.getAttacked(attackStrength);

    // Réduction des points de solidité de l'épée
    d_sword.reduceSolidity();
}

void player::getAttacked(int attackStrengthPoints) {
    // Initialisation des dégâts reçus par l'armure
    int armorDamage = static_cast<int>(attackStrengthPoints * 0.75);

    // Vérification de la possitibilité d'infliger tout les dégâts
    if(d_armor.solidityPoints() < armorDamage)
        // Ajustement du nombre de dégâts
        armorDamage = d_armor.solidityPoints();

    // Initialisation des dégâts reçus par l'aventurier
    int playerDamage = attackStrengthPoints - armorDamage;

    // Réception des dégâts par l'armure
    d_armor.getDamaged(armorDamage);
    // Réception des dégâts par l'aventurier
    getDamaged(playerDamage);
}

int moveChoice() {
    int choice {-1};
    do
    {
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

void player::move() {
   int moveC = moveChoice();
    switch (moveC) {
        case 1 : d_position.moveOn(d_position.x(),d_position.y() + 1);
            break;
        case 2 : d_position.moveOn(d_position.x(), d_position.y() - 1);
            break;
        case 3 : d_position.moveOn(d_position.x() + 1, d_position.y());
            break;
        case 4 : d_position.moveOn(d_position.x() - 1, d_position.y());
            break;
        case 5 : d_position.moveOn(d_position.x() - 1, d_position.y() + 1);
            break;
        case 6 : d_position.moveOn(d_position.x() + 1, d_position.y() + 1);
            break;
        case 7 : d_position.moveOn(d_position.x() - 1, d_position.y() - 1);
            break;
        case 8 : d_position.moveOn(d_position.x() + 1, d_position.y() - 1);
            break;
    }
}

void player::getCoins(int numberOfCoin) {
    // Incrémentation du nombre de pièces
    d_coins += numberOfCoin;
}