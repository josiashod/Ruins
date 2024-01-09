//
// Created by Daav on 18/11/2023.
//

#ifndef QUALITE_DE_PROG_CHARACTER_H
#define QUALITE_DE_PROG_CHARACTER_H

#include "GameElement.h"

class character : public GameElement {
public:
    /**
     * @brief Constructeur par défaut
     */
    character(char c, const std::string &nature);
    /**
     * @brief Constructeur par valeurs
     * @param c Le caractère représentant le personnage
     * @param nature La chaine de caractère identifiant le type de personnage
     * @param healthPoints Les points de vie du personnage
     * @param strenghtPoints Les points d'attaque du personnage
     */
    character(char c, const std::string &nature, int healthPoints, int strenghtPoints);
    /**
     * @brief Destructeur par défaut
     */
    virtual ~character() = default;

    /**
     * @brief Fonction renvoyant le nombre de points de vie
     * @return nombre de points de vie
     */
    int healthPoints() const;
    /**
      * @brief Fonction renvoyant le nombre de points de force
      * @return nombre de points de force
      */
    int strengthPoints() const;

    /**
     * @brief Méthode virtuelle permettant à un personnage d'en attaquer un autre
     * @param[in] c - Le personnage à attaquer
     */
    virtual void attack(character &c) const = 0;
    /**
     * @brief Méthode virtuelle permettant de gérer la réception d'une attaque sur un personnage
     * @param[in] attackStrengthPoints - Points de force de l'attaque
     */
    virtual void getAttacked(int attackStrengthPoints) = 0;
    /**
      * @brief Méthode permettant de gérer les dégâts infligés lors d'une attaque sur un personnage
      * @param[in] damage - Nombre de dégâts reçus
      */
    void getDamaged(int damage);
    /**
     * @brief Méthode permettant de faire mourir un personnage
     */
    void die();

    /**
     * @brief Méthode virtuelle permettant à un personnage de se déplacer
     */
    virtual void move() = 0;

    /**
     * @brief Fonction permettant de vérifier si un personnage est mort
     * @return true si le personnage est mort, false s'il est vivant
     */
    bool isDead() const;

protected:
    /**
     * Points de vie et points de force
     */
    int d_healthPoints, d_strengthPoints;
};


#endif //QUALITE_DE_PROG_CHARACTER_H
