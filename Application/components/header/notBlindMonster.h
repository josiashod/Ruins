//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_NOTBLINDMONSTER_H
#define QUALITE_DE_PROG_NOTBLINDMONSTER_H

#include "GameElement.h"
#include "monster.h"
#include "player.h"

class notBlindMonster : public monster {
public:
    /**
      * @brief Constructeur par défaut
      */
    notBlindMonster(player *p = nullptr);
    /**
     * @brief Constructeur par valeurs
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    notBlindMonster(int habilityPercentage, player *p = nullptr);
    /**
     * @brief Constructeur par valeurs
     * @param healthPoints Les points de vie du monstre
     * @param strenghtPoints Les points d'attaque du monstre
     * @param habilityPercentage Son taux d'habilieté au coups critiques
     */
    notBlindMonster(int healthPoints, int strenghtPoints, int habilityPercentage = 90, player *p = nullptr);

    /**
     * @brief Méthode retournant le joueur
     * @return d_player
     */
    player* getPlayer() const;

    /**
     * @brief Méthode retournant si le joueur est suffisanement proche du monstre
     * @param c Le joueur
     * @return true si le joueur est proche
     */
    bool isClose(character &c) const;
    /**
     * @brief Méthode retournant dans quelle direction se situe le joueur
     * @return Un entier représentant la direction
     */
    int direction(character &c) const;
    /**
     * @brief Méthode déplaçant le monstre
     */
    void move() override;

private :
    /// Pointeur vers le joueur
    player *d_player;
};


#endif //QUALITE_DE_PROG_NOTBLINDMONSTER_H
