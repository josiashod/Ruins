#ifndef PROJET_GAMEELEMENT_H
#define PROJET_GAMEELEMENT_H

#include "point.h"
#include <string>

/**
 * @brief La classe GameElement représente un élément de jeu caractérisé par un symbole, une position et une nature.
 */
class GameElement {
public:
    /**
     * @brief Constructeur de GameElement.
     * @param symbol Le symbole associé à l'élément de jeu.
     * @param p La position (point) de l'élément de jeu.
     * @param dNatureElement La nature de l'élément de jeu sous forme de chaîne de caractères.
     */
    GameElement(char symbol, const point &p, const std::string &dNatureElement);

    /**
     * @brief Renvoie le symbole de l'élément de jeu.
     * @return Le symbole de l'élément de jeu.
     */
    char getSymbol() const;

    /**
     * @brief Renvoie la coordonnée x de la position de l'élément de jeu.
     * @return La coordonnée x de la position de l'élément de jeu.
     */
    int getX() const;

    /**
     * @brief Renvoie la coordonnée y de la position de l'élément de jeu.
     * @return La coordonnée y de la position de l'élément de jeu.
     */
    int getY() const;

    /**
     * @brief Renvoie la nature de l'élément de jeu.
     * @return La nature de l'élément de jeu sous forme de chaîne de caractères.
     */
    std::string getNature() const;

    point point() const;

protected:
    /// Le symbole de l'élément de jeu.
    char d_symbol;

    /// La position de l'élément de jeu (coordonnées entières).
    point d_position;

    /// La nature de l'élément de jeu.
    std::string d_natureElement;
};
#endif //PROJET_GAMEELEMENT_H