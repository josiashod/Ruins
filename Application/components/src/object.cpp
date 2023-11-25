#include "../header/object.h"

object::object(int solidity): d_solidity{solidity} {
}

int object::solidity() const {
    return d_solidity;
}

void object::reduce(int nb) {
    if(nb > 0) d_solidity -= nb;
}
void object::increase(int nb) {
    if(nb > 0) d_solidity += nb;
}