#include "game.h"

game::game() : d_adventurer{std::make_shared<adventurer>()}, d_monsters{} {
    d_castle.init(d_adventurer, d_monsters);
}

int game::moveChoiceAdv() const
{
    int choice {-1};
    do {
        cout<<"Déplacement souhaité :\n";
        cout<<"(1) ↑ \n";
        cout<<"(2) ↓ \n";
        cout<<"(3) → \n";
        cout<<"(4) ← \n";
        cout<<"(5) ↖ \n";
        cout<<"(6) ↗ \n";
        cout<<"(7) ↙ \n";
        cout<<"(8) ↘ \n";
        cout<<"Votre choix : ";
        cin>>choice;
    } while(choice < 0 || choice > 8);
    return choice;
}

void game::moveAdventurer() {
    // int moveC = moveChoiceAdv();
    // switch (moveC) {
    //     case 1 : d_aventurer.move(d_aventurer.position.x(), d_aventurer.position.y() + 1);
    //         break;
    //     case 2 : d_aventurer.move(d_aventurer.position.x(), d_aventurer.position.y() - 1);
    //         break;
    //     case 3 : d_aventurer.move(d_aventurer.position.x() + 1, d_aventurer.position.y());
    //         break;
    //     case 4 : d_aventurer.move(d_aventurer.position.x() - 1, d_aventurer.position.y());
    //         break;
    //     case 5 : d_aventurer.move(d_aventurer.position.x() - 1, d_aventurer.position.y() + 1);
    //         break;
    //     case 6 : d_aventurer.move(d_aventurer.position.x() + 1, d_aventurer.position.y() + 1);
    //         break;
    //     case 7 : d_aventurer.move(d_aventurer.position.x() - 1, d_aventurer.position.y() - 1);
    //         break;
    //     case 8 : d_aventurer.move(d_aventurer.position.x() + 1, d_aventurer.position.y() - 1);
    //         break;
    // }
}