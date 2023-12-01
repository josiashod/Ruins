//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_BLINDMONSTER_H
#define QUALITE_DE_PROG_BLINDMONSTER_H

#include "monster.h"

class blindMonster : public monster {
public:
    /**
      * @brief Constructeur par défaut
      */
    blindMonster();
    /**
     * @brief Constructeur par valeurs
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    blindMonster(int habilityPercentage);
    /**
     * @brief Constructeur par valeurs
     * @param healthPoints Les points de vie du monstre
     * @param strenghtPoints Les points d'attaque du monstre
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    blindMonster(int healthPoints, int strenghtPoints, int habilityPercentage = 90);

    /**
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un monstre aveugle de se déplacer
      */
    void move() override;
};


#endif //QUALITE_DE_PROG_BLINDMONSTER_H
