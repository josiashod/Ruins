//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_MONSTER_H
#define QUALITE_DE_PROG_MONSTER_H

#include "character.h"
#include "adventurer.h"

class monster : public character {
public :
    /**
     * @brief Constructeur par valeurs
     * @param health Les points de vie du monstre
     * @param strenght Les points d'attaque du monstre
     * @param hability Son taux d'habilieté au coups critiques
     */
    monster(int health = 70, int strenght = 5, double hability = 90, adventurer *adventurer = nullptr);
    /**
      * @brief Destructeur par défaut
      */
    virtual ~monster() = default;

    /**
      * @brief Fonction renvoyant le pourcentage d'habilité
      * @return poucentage d'habilité
      */
    int hability() const;
    /**
     * @brief Fonction renvoyant le pointeur pointant vers l'aventurier
     * @return
     */
    adventurer* adventurer() const;

    /**
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un monstre d'attaquer un personnage
      * @param[in] c - Le personnage à attaquer
      */
    void attack(character &c) override;
    /**
      * @brief Réecriture de la méthode virtuelle permettant de gérer la réception d'une attaque par un monstre
      * @param[in] attackStrengthPoints - Points de force de l'attaque
      */
    void hasBeenAttacked(int attackStrengthPoints) override;

    /**
      * @brief Méthode retournant si le joueur est suffisanement proche du monstre
      * @param c Le joueur
      * @return true si le joueur est proche
      */
    bool isClose() const;
    /**
     * @brief Méthode retournant dans quelle direction se situe le joueur
     * @return Un entier représentant la direction
     */
    int direction() const;

    /**
     * @brief Méthode virtuelle permettant à un monstre de se déplacer
     */
    virtual void move();
private:
    /// Pourcentage d'habilité du monstre
    double d_hability;

    /// Pointeur vers l'aventurier
    class adventurer *d_adventurer;
};

#endif //QUALITE_DE_PROG_MONSTER_H
