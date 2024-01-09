//
// Created by Daav on 18/11/2023.
//

#include <cstdlib>
#include "monster.h"
#include "castle.h"

monster::monster(int health, int strength, double hability, std::string type)
    : character{health, strength, type}, d_hability{hability}
{}

int monster::hability() const {
    // Renvoi du pourcentage d'habilité
    return d_hability;
}

void monster::attack(character &c) {
    // Initialisation de la force d'attaque
    int attackStrength = d_strength;
    // Génération d'un nombre aléatoire entre 0 et 99 et vérification de l'infériorité de ce nombre à 80
    if ((rand() % 100) < d_hability)
        // Si la probabilité est générée inférieure au pourcentage d'habilité, on multiplie la force d'attaque par 0,9
        attackStrength = static_cast<int>(attackStrength * 0.9);
    // Lancement de l'attaque sur le personnage c
    c.hasBeenAttacked(attackStrength);
}

void monster::hasBeenAttacked(int attackStrengthPoints) {
    // Initialisation des dégâts reçus par le monstre
    int monsterDamage = attackStrengthPoints;
    // Réception des dégâts par le monstre
    getDamaged(monsterDamage);
}

bool monster::isClose(std::shared_ptr<adventurer> &adventurer) const {
    // Calcul de la distance entre le monstre et l'aventurier
    int distance = position().distance(adventurer->position());
    // Renvoi de vrai si la distance est inférieur à 8
    return distance < 8;
}

int monster::direction(std::shared_ptr<adventurer> &adventurer) const
{
    if(position().y() > adventurer->position().y())
    {
        if(position().x() > adventurer->position().x()) return 5;
        if(position().x() < adventurer->position().x()) return 6;
        return 1;
    }
    else if(position().y() < adventurer->position().y())
    {
        if(position().x() > adventurer->position().x()) return 7;
        if(position().x() < adventurer->position().x()) return 8;
        return 2;
    }
    else
    {
        if(position().x() > adventurer->position().x()) return 4;
        // if(position().x() < d_adventurer->position().x()) return 3;
    }
    return 3;
}

/*void monster::move(std::shared_ptr<adventurer> &adventurer) {
    if(isClose(adventurer)) {
        int d = direction(adventurer);
        switch (d) {
            case 1 : character::move(position().x(), position().y() + 1);
                break;
            case 2 : character::move(position().x(), position().y() - 1);
                break;
            case 3 : character::move(position().x() + 1, position().y());
                break;
            case 4 : character::move(position().x() - 1, position().y());
                break;
            case 5 : character::move(position().x() - 1, position().y() + 1);
                break;
            case 6 : character::move(position().x() + 1, position().y() + 1);
                break;
            case 7 : character::move(position().x() - 1, position().y() - 1);
                break;
            case 8 : character::move(position().x() + 1, position().y() - 1);
                break;
        }
    }
}*/

void monster::move(castle &castle, std::shared_ptr<adventurer> &adventurer, std::shared_ptr<monster> &monster) {
    if(isClose(adventurer)) {
        int d = direction(adventurer);
        int newX = position().x();
        int newY = position().y();

        switch(d) {
            case 1: newY += 1; break;
            case 2: newY -= 1; break;
            case 3: newX += 1; break;
            case 4: newX -= 1; break;
            case 5: newX -= 1; newY += 1; break;
            case 6: newX += 1; newY += 1; break;
            case 7: newX -= 1; newY -= 1; break;
            case 8: newX += 1; newY -= 1; break;
        }

        if(newX >= 0 && newY >= 0 && newY < castle.d_boxes.size() && newX < castle.d_boxes[0].size()) {
            if(castle.d_boxes[newX][newY].accessibility()) {
                castle.d_boxes[position().x()][position().y()].removeCharacter();
                character::move(newX, newY);
                castle.d_boxes[newX][newY].putCharacter(monster);
            }
        }
    }
}

void monster::show(display &d) const
{
    d.displayMonster();
}
