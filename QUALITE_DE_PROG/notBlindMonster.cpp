//
// Created by Daav on 18/11/2023.
//

#include "notBlindMonster.h"

notBlindMonster::notBlindMonster() : monster{} {}

bool notBlindMonster::isClose(character &c) const {
    int distance = d_position.distance(c.point());
    if(distance < 8) {

    }
    else {

    }
}