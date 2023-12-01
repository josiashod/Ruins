#include "../header/point.h"
#include <cmath>

/**
 * @brief La classe point représente un point dans un espace à deux dimensions avec des coordonnées entières.
 */
point::point(int x, int y) :
        d_x{x}, d_y{y}
{
}

/**
 * @brief Constructeur par défaut initialisant le point à l'origine (0,0).
 */
point::point() :
        d_x{0}, d_y{0}
{
}

/**
 * @brief Renvoie l'abscisse du point.
 * @return L'abscisse du point.
 */
int point::x() const
{
    return d_x;
}

/**
 * @brief Renvoie l'ordonnée du point.
 * @return L'ordonnée du point.
 */
int point::y() const
{
    return d_y;
}

/**
 * @brief Déplace le point vers de nouvelles coordonnées (x, y).
 * @param x La nouvelle abscisse.
 * @param y La nouvelle ordonnée.
 */
void point::moveOn(int x, int y)
{
    d_x = x;
    d_y = y;
}

/**
 * @brief Déplace le point de (deltax, deltay) par rapport à ses coordonnées actuelles.
 * @param deltax Le déplacement en abscisse.
 * @param deltay Le déplacement en ordonnée.
 */
void point::moveOff(int deltax, int deltay)
{
    d_x += deltax;
    d_y += deltay;
}

/**
 * @brief Renvoie la distance entre le point courant et un autre point p.
 * @param p2 Le point avec lequel calculer la distance.
 * @return La distance entre les deux points.
 */
double point::distance(const point &p) const
{
    int dx = p.x() - d_x;
    int dy = p.y() - d_y;
    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Surcharge de l'opérateur d'égalité.
 * @param p2 Le point à comparer.
 * @return True si les points sont égaux, False sinon.
 */
bool point::operator==(const point &p2) const
{
    return (x() == p2.x() && y() == p2.y());
}

/**
 * @brief Surcharge de l'opérateur de différence.
 * @param p2 Le point à comparer.
 * @return True si les points sont différents, False sinon.
 */
bool point::operator!=(const point &p2) const
{
    return (x() != p2.x() || y() != p2.y());
}

/**
 * @brief Surcharge de l'opérateur d'addition composée.
 * @param p2 Le point à ajouter.
 * @return Une référence vers le point résultant de l'addition.
 */
point &point::operator+=(const point &p2)
{
    moveOff(p2.x(), p2.y());
    return *this;
}

/**
 * @brief Surcharge de l'opérateur d'affectation.
 * @param p2 Le point à copier.
 * @return Une référence vers le point courant après l'affectation.
 */
point &point::operator=(const point &p2)
{
    moveOn(p2.x(), p2.y());
    return *this;
}

/**
 * @brief Surcharge de l'opérateur de soustraction composée.
 * @param p2 Le point à soustraire.
 * @return Une référence vers le point résultant de la soustraction.
 */
point &point::operator-=(const point &p2)
{
    moveOff(-p2.x(), -p2.y());
    return *this;
}

/**
 * @brief Surcharge de l'opérateur de sortie pour afficher un point.
 * @param ost Le flux de sortie.
 * @param p Le point à afficher.
 * @return Une référence vers le flux de sortie.
 */
std::ostream &operator<<(std::ostream &ost, const point &p)
{
    ost << '[' << p.x() << ',' << p.y() << ']' << std::endl;
    return ost;
}

/**
 * @brief Surcharge de l'opérateur d'entrée pour lire un point.
 * @param ist Le flux d'entrée.
 * @param p Le point à remplir.
 * @return Une référence vers le flux d'entrée.
 */
std::istream &operator>>(std::istream &ist, point &p)
{
    char trash;
    int x, y;
    ist >> trash >> x >> trash >> y >> trash;
    p.moveOn(x, y);
    return ist;
}