#ifndef PROJET_GAMEELEMENT_H
#define PROJET_GAMEELEMENT_H

#include "point.h"

class GameElement{
public:
    GameElement(char symbol,const point&p,const std::string &dNatureElement);
    char getSymbol()const;
    double getX()const;
    double getY() const;
    std::string getNature()const;
    virtual ~GameElement()=0;
private:
    char d_symbol;
    point d_position;
    std::string d_natureElement;
};

#endif //PROJET_GAMEELEMENT_H
