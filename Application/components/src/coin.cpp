//
// Created by Daav on 01/12/2023.
//

#include "../header/coin.h"

coin::coin(player *p, int amount) : emptyCase('C', "Pièce"), d_player{p}, d_amount{amount} {}

int coin::amount() const {
    return d_amount;
}

void coin::changeAmount(int amount) {
    d_amount = amount;
}

void coin::isTaken() {
    if(d_player->GetPosition() == GetPosition())
        switchBeAccessible();
}