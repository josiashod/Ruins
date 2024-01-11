#include "equipment.h"

equipment::equipment(int solidity): d_solidity{solidity} {
}

int equipment::solidity() const {
    return d_solidity;
}

void equipment::reduce(int nb) {
    if(nb > 0) d_solidity -= nb;
}
void equipment::increase(int nb) {
    if(nb > 0) d_solidity += nb;
}

void equipment::setSolidity(int value) {
    d_solidity = value;
}