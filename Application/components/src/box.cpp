#include "../header/box.h"

const std::string box::BX_WALL = "wall";
const std::string box::BX_EMPTY = "empty";
const std::string box::BX_COINS = "coins";
const std::string box::BX_EXTERN = "extern";
const std::string box::BX_AMULET = "amulet";

box::box(const std::string &type, int coins, character *c) : d_type{type}, d_coins{coins}, d_character{c}
{
    if(d_type == box::BX_WALL || d_type == box::BX_EXTERN)
        d_accessibility = false;
    else
    {
        if(d_type == box::BX_AMULET)
            d_amulet = true;
        d_accessibility = true;
    }
}

std::string box::type() const {
    return d_type;
}

bool box::accessibility() const {
    return d_accessibility;
}

int box::coins() const {
    return d_coins;
}

void box::putCharacter(character *c) {
    d_character = c;
}

void box::removeCharacter() {
    d_character = nullptr;
}

void box::removeCoin() {
    d_coins = 0;
    changeType(box::BX_EMPTY);
}

void box::removeAmulet() {
    d_amulet = false;
    changeType(box::BX_EMPTY);
}

void box::changeType(const std::string &type) {
    d_type = type;
}