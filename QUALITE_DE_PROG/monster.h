//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_MONSTER_H
#define QUALITE_DE_PROG_MONSTER_H

#include "character.h"

class monster : public character {
public:
    /**
      * @brief Destructeur par défaut
      */
    virtual ~monster() = default;

    /**
      * @brief Constructeur par défaut
      */
    monster(char c, const std::string &nature);

    /**
     * Constrcteur de monstre à partir d'un pourcentage d'habilité
     * @param habilityPercentage - Pourcentage d'habilité du monstre
     */
    monster(char c, const std::string &nature, int habilityPercentage);

    /**
      * @brief Fonction renvoyant le pourcentage d'habilité
      * @return poucentage d'habilité
      */
    int habilityPercentage() const;

    /**
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un monstre d'attaquer un personnage
      * @param[in] c - Le personnage à attaquer
      */
    void attack(character &c) const override;

    /**
      * @brief Réecriture de la méthode virtuelle permettant de gérer la réception d'une attaque par un monstre
      * @param[in] attackStrengthPoints - Points de force de l'attaque
      */
    void getAttacked(int attackStrengthPoints) override;
private:
    int d_habilityPercentage;
};

#endif //QUALITE_DE_PROG_MONSTER_H
