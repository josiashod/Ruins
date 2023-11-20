//
// Created by Daav on 18/11/2023.
//
#ifndef QUALITE_DE_PROG_PLAYER_H
#define QUALITE_DE_PROG_PLAYER_H

#include "character.h"
class sword;
class armor;

class player : public character {
public:
    /**
      * @brief Constructeur par défaut
      */
    player();

    /**
      * @brief Fonction renvoyant le nombre de pièces
      * @return nombre de pièces
      */
    int coins() const;

    /**
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un aventurier d'attaquer un personnage
      * @param[in] c - Le personnage à attaquer
      */
    void attack(character &c) const override;
    /**
      * @brief Réecriture de la méthode virtuelle permettant de gérer la réception d'une attaque par un aventurier
      * @param[in] attackStrengthPoints - Points de force de l'attaque
      */
    void getAttacked(int attackStrengthPoints) override;

    /**
     * @brief Fonction renvoyant le choix de déplacement de l'utilisateur
     * @return la valeur correspondant au choix de déplacement
     */
    int moveChoice();
    /**
      * @brief Réecriture de la méthode virtuelle permettant ainsi à un aventurer de se déplacer
      */
    void move() override;

    /**
      * @brief Méthode permettant à un aventurier de gagner un nombre de pièce
      */
    void getCoins(int numberOfCoin);

private:
    int d_coins;
    sword d_sword;
    armor d_armor;
};


#endif //QUALITE_DE_PROG_PLAYER_H
