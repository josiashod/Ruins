//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_MONSTER_H
#define QUALITE_DE_PROG_MONSTER_H

#include "character.h"

class monster : public character {
public :
    /**
     * @brief Constructeur par défaut
     * @param c Le caractère représentant le monsre
     * @param nature La chaine de caractère identifiant le type de monstre
     */
    monster(char c, const std::string &nature);
    /**
     * @brief Constructeur de monstre à partir d'un pourcentage d'habilité
     * @param c Le caractère représentant le monsre
     * @param nature La chaine de caractère identifiant le type de monstre
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    monster(char c, const std::string &nature, int habilityPercentage);
    /**
     * @brief Constructeur par valeurs
     * @param c Le caractère représentant le monsre
     * @param nature La chaine de caractère identifiant le type de monstre
     * @param healthPoints Les points de vie du monstre
     * @param strenghtPoints Les points d'attaque du monstre
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    monster(char c, const std::string &nature, int healthPoints, int strenghtPoints, int habilityPercentage = 90);
    /**
      * @brief Destructeur par défaut
      */
    virtual ~monster() = default;

    /**
      * @brief Fonction renvoyant le pourcentage d'habilité
      * @return poucentage d'habilité
      */
    int habilityPercentage() const;

    /**
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un monstre d'attaquer un personnage
      * @param[in] c - Le personnage à attaquer
      */
    void attack(character &c) override;
    /**
      * @brief Réecriture de la méthode virtuelle permettant de gérer la réception d'une attaque par un monstre
      * @param[in] attackStrengthPoints - Points de force de l'attaque
      */
    void getAttacked(int attackStrengthPoints) override;

private:
    int d_habilityPercentage;
};

#endif //QUALITE_DE_PROG_MONSTER_H
