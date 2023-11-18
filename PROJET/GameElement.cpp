//
// Created by User on 18/11/2023.
//

#include "GameElement.h"

GameElement::GameElement(char symbol,const point&p,const std::string &dNatureElement):
    d_symbol{symbol},d_position{p},d_natureElement{dNatureElement}
{}
char GameElement::getSymbol()const
{
    return d_symbol;
}

std::string GameElement::getNature()const
{
    return d_natureElement;
}

double GameElement::getX() const
{
    return d_position.x();
}
double GameElement::getY() const
{
    return d_position.y();
}