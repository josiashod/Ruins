#include "GameElement.h"

/**
 * @brief Constructeur de la classe GameElement.
 * @param symbol Le symbole associé à l'élément de jeu.
 * @param p La position (point) de l'élément de jeu.
 * @param dNatureElement La nature de l'élément de jeu sous forme de chaîne de caractères.
 */
GameElement::GameElement(char symbol, const point &p, const std::string &dNatureElement) :
        d_symbol{symbol}, d_position{p}, d_natureElement{dNatureElement}
{}

/**
 * @brief Renvoie le symbole de l'élément de jeu.
 * @return Le symbole de l'élément de jeu.
 */
char GameElement::getSymbol() const
{
    return d_symbol;
}

/**
 * @brief Renvoie la nature de l'élément de jeu.
 * @return La nature de l'élément de jeu sous forme de chaîne de caractères.
 */
std::string GameElement::getNature() const
{
    return d_natureElement;
}

/**
 * @brief Renvoie la coordonnée x de la position de l'élément de jeu.
 * @return La coordonnée x de la position de l'élément de jeu.
 */
int GameElement::getX() const
{
    return d_position.x();
}

/**
 * @brief Renvoie la coordonnée y de la position de l'élément de jeu.
 * @return La coordonnée y de la position de l'élément de jeu.
 */
int GameElement::getY() const
{
    return d_position.y();
}