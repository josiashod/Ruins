//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_NOTBLINDMONSTER_H
#define QUALITE_DE_PROG_NOTBLINDMONSTER_H

#include "monster.h"
#include "player.h"

class notBlindMonster : monster {
public:
    /**
      * @brief Constructeur par défaut
      */
    notBlindMonster();
    /**
     * @brief Constructeur par valeurs
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    notBlindMonster(int habilityPercentage);
    /**
     * @brief Constructeur par valeurs
     * @param healthPoints Les points de vie du monstre
     * @param strenghtPoints Les points d'attaque du monstre
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    notBlindMonster(int healthPoints, int strenghtPoints, int habilityPercentage = 90);


    /**
     * @brief Méthode retournant si le joueur est assez proche du monstre
     * @param c Le joueur
     * @return true si le joueur est assez proche
     */
    bool isClose(character &c) const;
    /**
     * @brief Méthode retournant la direction dans laquelle se situe le joueur
     * @return La direction
     */
    int direction(character &c) const;
    /**
     * @brief Méthode déplaçant le monstre selon la position du joueur
     * @param p Le joueur
     */
    void move(character &p);
};


#endif //QUALITE_DE_PROG_NOTBLINDMONSTER_H
