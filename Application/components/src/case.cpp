//
// Created by Daav on 09/12/2023.
//

#include "../header/case.h"

caseG::caseG(const std::string &type, int coins, character *c) : d_type{type}, d_coins{coins}, d_character{c} {
    if(type == "Case Vide" || type == "Case Pièce" || type == "Case Amulette") {
        if (type == "Case Amulette")
            d_isAmulette = true;
        d_accessibility = true;
    }
    else if(type == "Mur" || type == "Case Externe")
        d_accessibility = false;
}

std::string caseG::type() const {
    return d_type;
}

bool caseG::accesibility() const {
    return d_accessibility;
}

int caseG::coins() const {
    return d_coins;
}

void caseG::addCharacter(character *c) {
    d_character = c;
}

void caseG::removeCharacter() {
    d_character = nullptr;
}

void caseG::removeCoin() {
    d_coins = 0;
    changeType("Case Vide");
}

void caseG::removeAmulette() {
    d_isAmulette = false;
    changeType("Case Vide");
}

void caseG::changeType(const std::string &type) {
    d_type = type;
}