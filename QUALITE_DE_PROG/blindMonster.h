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
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un monstre aveugle de se déplacer
      */
    void move() override;
};


#endif //QUALITE_DE_PROG_BLINDMONSTER_H
