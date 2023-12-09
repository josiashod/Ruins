//
// Created by Daav on 09/12/2023.
//

#ifndef APPLICATION_CASE_H
#define APPLICATION_CASE_H

#include <iostream>
#include "character.h"

class caseG {
public:
    caseG(const std::string &type, int coins = 0, character* c = nullptr);
    std::string type() const;
    bool accesibility() const;
    int coins() const;
    void addCharacter(character *c);
    void removeCharacter();
    void removeCoin();
    void removeAmulette();
    void changeType(const std::string &type);
private:
    character *d_character;
    std::string d_type;
    bool d_accessibility, d_isAmulette;
    int d_coins;
};


#endif //APPLICATION_CASE_H
