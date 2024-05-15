#ifndef PROJET_DISPLAY_H
#define PROJET_DISPLAY_H

#include <string>

class display
{
public:
    void displayAdventurer();
    void displayMonster();
    void displayBlindMonster();
    void displayAmulet();
    void displayWall();
    void displayEmptyCase();
    void displayExternCase();
    void displayCoin();
private:
    // colors
    static const std::string BLACK;
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string WHITE;
    static const std::string PURPLE;
    static const std::string CYAN;
};


#endif //PROJET_DISPLAY_H
