//
// Created by Daav on 18/11/2023.
//
#include "../header/notBlindMonster.h"

notBlindMonster::notBlindMonster():monster{'V', "Monstre Voyant"}{
}

notBlindMonster::notBlindMonster(int habilityPercentage)
    :monster{'V', "Monstre Voyant", habilityPercentage}{
}

notBlindMonster::notBlindMonster(int healthPoints, int strenghtPoints, int habilityPercentage)
        :monster{'V', "Monstre Voyant", healthPoints, strenghtPoints, habilityPercentage}{
}

bool notBlindMonster::isClose(character &c) const {
    int distance = GetPosition().distance(c.GetPosition());
    return distance < 8;
}

int notBlindMonster::direction(character &c) const {
    if(GetPosition().y() < c.GetPosition().y()){
        if(GetPosition().x() < c.GetPosition().x()) return 8;
        if(GetPosition().x() == c.GetPosition().x()) return 2;
        return 7;
    } else if(GetPosition().y() > c.GetPosition().y()){
        if(GetPosition().x() < c.GetPosition().x()) return 6;
        if(GetPosition().x() == c.GetPosition().x()) return 1;
        return 5;
    } else {
        if(GetPosition().y() < c.GetPosition().y()) return 3;
        return 4;
    }
}

void notBlindMonster::move(character &p) {
    if(isClose(p)){
        int choice {direction(p)};
        switch (choice) {
            case 1 : MoveElement(GetPosition().x(), GetPosition().y() + 1);
                break;
            case 2 : MoveElement(GetPosition().x(), GetPosition().y() - 1);
                break;
            case 3 : MoveElement(GetPosition().x() + 1, GetPosition().y());
                break;
            case 4 : MoveElement(GetPosition().x() - 1, GetPosition().y());
                break;
            case 5 : MoveElement(GetPosition().x() - 1, GetPosition().y() + 1);
                break;
            case 6 : MoveElement(GetPosition().x() + 1, GetPosition().y() + 1);
                break;
            case 7 : MoveElement(GetPosition().x() - 1, GetPosition().y() - 1);
                break;
            case 8 : MoveElement(GetPosition().x() + 1, GetPosition().y() - 1);
                break;
        }
    }
}