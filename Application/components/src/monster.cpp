//
// Created by Daav on 18/11/2023.
//

#include <cstdlib>
#include "../header/monster.h"

monster::monster(char c, const std::string &nature) : character{c, nature}, d_habilityPercentage{90}{
}

monster::monster(char c, const std::string &nature, int habilityPercentage)
    : character{c, nature}, d_habilityPercentage{habilityPercentage}{
}

monster::monster(char c, const std::string &nature, int healthPoints, int strenghtPoints, int habilityPercentage)
    : character{c, nature, healthPoints, strenghtPoints}, d_habilityPercentage{habilityPercentage}{
}

int monster::habilityPercentage() const {
    // Renvoi du pourcentage d'habilité
    return d_habilityPercentage;
}

void monster::attack(character &c) {
    // Initialisation de la force d'attaque
    int attackStrength = d_strengthPoints;
    // Génération d'un nombre aléatoire entre 0 et 99 et vérification de l'infériorité de ce nombre à 80
    if ((rand() % 100) < d_habilityPercentage)
        // Si la probabilité est générée inférieure au pourcentage d'habilité, on multiplie la force d'attaque par 0,9
        attackStrength = static_cast<int>(attackStrength * 0.9);
    // Lancement de l'attaque sur le personnage c
    c.getAttacked(attackStrength);
}

void monster::getAttacked(int attackStrengthPoints) {
    // Initialisation des dégâts reçus par le monstre
    int playerDamage = attackStrengthPoints;
    // Réception des dégâts par le monstre
    getDamaged(playerDamage);
}

