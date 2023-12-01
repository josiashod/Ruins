//
// Created by Daav on 01/12/2023.
//

#include "../header/coin.h"

coin::coin(int amount, int x, int y) : GameElement('P', {x,y}, "Pièce"), d_amount{amount} {}

int coin::amount() const {
    return d_amount;
}

void coin::changeAmount(int amount) {
    d_amount = amount;
}

bool coin::isTaken(const player &p) const {
    return p.GetPosition() == GetPosition();
}