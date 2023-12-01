//
// Created by Daav on 01/12/2023.
//

#ifndef APPLICATION_COIN_H
#define APPLICATION_COIN_H

#include "player.h"

class coin : public GameElement {
public:
    coin(int amount, int x, int y);
    int amount() const;
    void changeAmount(int amount);
    bool isTaken(const player &p) const;
private:
    int d_amount;
};


#endif //APPLICATION_COIN_H
