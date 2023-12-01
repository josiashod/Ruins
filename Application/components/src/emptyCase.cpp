//
// Created by Daav on 01/12/2023.
//

#include "../header/emptyCase.h"

emptyCase::emptyCase() : GameElement('E', {}, "Case vide") {}

emptyCase::emptyCase(char c, const std::string &nature) : GameElement{c, {}, nature} {}

void emptyCase::switchBeAccessible() {
    if(!isAccesible())
    {
        beAccessible();
        // Changer le caractère et la nature
    }
}

void emptyCase::switchNotAccessible() {
    if(isAccesible())
    {
        notAccessible();
        // Changer le caractère et la nature
    }
}