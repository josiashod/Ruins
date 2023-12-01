//
// Created by Daav on 01/12/2023.
//

#ifndef APPLICATION_EMPTYCASE_H
#define APPLICATION_EMPTYCASE_H

#include "GameElement.h"

class emptyCase : public GameElement {
public:
    emptyCase();
    emptyCase(char c, const std::string &nature);
    void switchBeAccessible();
    void switchNotAccessible();
};


#endif //APPLICATION_EMPTYCASE_H
