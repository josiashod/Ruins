//
// Created by Daav on 18/11/2023.
//

#include "character.h"

character::character(char c, const std::string &nature) : GameElement{c, {}, nature}, d_healthPoints{100}, d_strengthPoints{10} {}

int character::healthPoints() const {
    // Renvoi du nombre de points de vie
    return d_healthPoints;
}

int character::strengthPoints() const {
    // Renvoi du nombre de points de force
    return d_strengthPoints;
}

void character::getDamaged(int damage) {
    d_healthPoints -= damage;
    if (isDead()) {
        die();
    }
}

void character::die() {
    // Mise à zéro des points de vie et de force
    d_healthPoints = 0;
    d_strengthPoints = 0;

    // Le faire disparaître de la map
}

bool character::isDead() const {
    // Vérification du nombre de points de vie
    if(d_healthPoints <= 0)
        // Renvoi de vrai si la valeur est négative ou égale à 0
        return true;
    // Renvoi de faux si la valeur est positive
    return false;
}


