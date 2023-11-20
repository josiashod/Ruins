//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_NOTBLINDMONSTER_H
#define QUALITE_DE_PROG_NOTBLINDMONSTER_H

#include "monster.h"

class notBlindMonster : monster {
public:
    /**
      * @brief Constructeur par défaut
      */
    notBlindMonster();

    bool isClose(character &c) const;

    /**
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un monstre voyant de se déplacer
      */
    void move() override;
};


#endif //QUALITE_DE_PROG_NOTBLINDMONSTER_H
