#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include<iostream>

class point
{
public:
    /**
    constructeur avec coordonnées carthésiennes
    @param x l'abscisse du point
    @param y l'ordonnée du point
    */
    point(double x, double y);
    /**
    Constructeur par défaut : l'origine (0,0)
    */
    point();
    /**
    Renvoie l'abscisse du point
    @return l'abscisse du point
    */
    double x() const;
    /**
    Renvoie l'ordonnée du point
    @return l'ordonnée du point
    */
    double y() const;


    void moveOn(double x, double y);

    void moveOff(double deltax, double deltay);

    /**
    @return la distance du point courant au point p*/
    double distance(const point&p2) const;

    bool operator==(const point&p2)const;
    bool operator!=(const point&p2)const;

    point& operator+=(const point &p2);
    point& operator=(const point &p2);
    point&operator-=(const point &p2);
private:
    ///coordonnées carthésiennes
    double d_x, d_y;

};

std::ostream& operator<<(std:: ostream&ost,const point &p);
std::istream & operator>>(std:: istream&ist,const point &p);
//p1 = p2 p1.operator=(p2)

#endif // HEAD_H_INCLUDED
