//
// Created by Daav on 01/12/2023.
//

#ifndef APPLICATION_COIN_H
#define APPLICATION_COIN_H

#include "emptyCase.h"
#include "player.h"

class coin : public emptyCase {
public:
    coin(player *p, int amount);
    int amount() const;
    void changeAmount(int amount);
    void isTaken();
private:
    int d_amount;
    player *d_player;
};


#endif //APPLICATION_COIN_H
