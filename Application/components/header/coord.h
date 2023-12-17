#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include<iostream>

/**
 * @brief La classe point représente un point dans un espace à deux dimensions avec des coordonnées entières.
 */
class coord
{
public:
    /**
 * @brief Constructeur par défaut initialisant le point à l'origine (0,0).
 */
    coord();
    /**
     * @brief Constructeur avec coordonnées entières.
     * @param x L'abscisse du point.
     * @param y L'ordonnée du point.
     */
    coord(int x, int y);

    /**
     * @brief Renvoie l'abscisse du point.
     * @return L'abscisse du point.
     */
    int x() const;
    /**
     * @brief Renvoie l'ordonnée du point.
     * @return L'ordonnée du point.
     */
    int y() const;
    /**
     * @brief Renvoie la distance entre le point courant et un autre point p.
     * @param p2 Le point avec lequel calculer la distance.
     * @return La distance entre les deux points.
     */
    double distance(const coord &p2) const;

    /**
     * @brief Déplace le point vers de nouvelles coordonnées (x, y).
     * @param x La nouvelle abscisse.
     * @param y La nouvelle ordonnée.
     */
    void moveOn(int x, int y);
    /**
     * @brief Déplace le point de (deltax, deltay) par rapport à ses coordonnées actuelles.
     * @param deltax Le déplacement en abscisse.
     * @param deltay Le déplacement en ordonnée.
     */
    void moveOff(int deltax, int deltay);

    /**
     * @brief Surcharge de l'opérateur d'égalité.
     * @param p2 Le point à comparer.
     * @return True si les points sont égaux, False sinon.
     */
    bool operator==(const coord &p2) const;

    /**
     * @brief Surcharge de l'opérateur de différence.
     * @param p2 Le point à comparer.
     * @return True si les points sont différents, False sinon.
     */
    bool operator!=(const coord &p2) const;

    /**
     * @brief Surcharge de l'opérateur d'addition composée.
     * @param p2 Le point à ajouter.
     * @return Une référence vers le point résultant de l'addition.
     */
    coord &operator+=(const coord &p2);
    /**
     * @brief Surcharge de l'opérateur de soustraction composée.
     * @param p2 Le point à soustraire.
     * @return Une référence vers le point résultant de la soustraction.
     */
    coord &operator-=(const coord &p2);
    /**
     * @brief Surcharge de l'opérateur d'affectation.
     * @param p2 Le point à copier.
     * @return Une référence vers le point courant après l'affectation.
     */
    coord &operator=(const coord &p2);

private:
    /// Coordonnées entières du point.
    int d_x, d_y;
};

/**
 * @brief Surcharge de l'opérateur de sortie pour afficher un point.
 * @param ost Le flux de sortie.
 * @param p Le point à afficher.
 * @return Une référence vers le flux de sortie.
 */
std::ostream &operator<<(std::ostream &ost, const coord &p);

/**
 * @brief Surcharge de l'opérateur d'entrée pour lire un point.
 * @param ist Le flux d'entrée.
 * @param p Le point à remplir.
 * @return Une référence vers le flux d'entrée.
 */
std::istream &operator>>(std::istream &ist, coord &p);

#endif // HEAD_H_INCLUDED
