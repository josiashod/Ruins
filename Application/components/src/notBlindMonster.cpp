//
// Created by Daav on 18/11/2023.
//

#include "../header/notBlindMonster.h"

notBlindMonster::notBlindMonster(player *p):monster{'V', "Monstre Voyant"}, d_player{p}{
}

notBlindMonster::notBlindMonster(int habilityPercentage, player *p)
    :monster{'V', "Monstre Voyant", habilityPercentage}, d_player{p}{
}

notBlindMonster::notBlindMonster(int healthPoints, int strenghtPoints, int habilityPercentage, player *p)
    :monster{'V', "Monstre Voyant", healthPoints, strenghtPoints, habilityPercentage}, d_player{p}{
}

player* notBlindMonster::getPlayer() const{
    return d_player;
}

bool notBlindMonster::isClose(character &c) const {
    int distance = GetPosition().distance(c.GetPosition());
    return distance < 8;
}

int notBlindMonster::direction(character &c) const {
    if(getY() > c.getY()){
        if(getX() > c.getX()) return 5;
        if(getX() < c.getX()) return 6;
        return 1;
    } else if(getY() < c.getY()){
        if(getX() > c.getX()) return 7;
        if(getX() < c.getX()) return 8;
        return 2;
    } else {
        if(getX() > c.getX()) return 4;
        if(getX() < c.getX()) return 3;
    }
}

void notBlindMonster::move(){
    if(isClose(reinterpret_cast<character &>(d_player))){
        int d = direction(reinterpret_cast<character &>(d_player));
        switch (d) {
            case 1 : MoveElement(getX(), getY() + 1);
                break;
            case 2 : MoveElement(getX(), getY() - 1);
                break;
            case 3 : MoveElement(getX() + 1, getY());
                break;
            case 4 : MoveElement(getX() - 1, getY());
                break;
            case 5 : MoveElement(getX() - 1, getY() + 1);
                break;
            case 6 : MoveElement(getX() + 1, getY() + 1);
                break;
            case 7 : MoveElement(getX() - 1, getY() - 1);
                break;
            case 8 : MoveElement(getX() + 1, getY() - 1);
                break;
        }
    }
}