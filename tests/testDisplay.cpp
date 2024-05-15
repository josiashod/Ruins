#include "doctest.h"
#include "../display.h"
<<<<<<< HEAD
#include <iostream>
#include <sstream>
=======
>>>>>>> origin/josh

TEST_CASE("[display] Tests des fonctions de la classe display")
{
    display objetAffichage;

    SUBCASE("Test de displayAdventurer()")
    {
<<<<<<< HEAD
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayAdventurer();

        std::string sortie = oss.str();
        // Vérifier si la sortie contient "P" et la couleur blanche
        REQUIRE(sortie.find("P") != std::string::npos);
        REQUIRE(sortie.find(display::WHITE) != std::string::npos);
=======
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        objetAffichage.displayAdventurer();

        std::string sortie = buffer.str();
        REQUIRE_EQ(sortie, "A");
>>>>>>> origin/josh

        std::cout.rdbuf(old);
    }

    SUBCASE("Test de displayMonster()")
    {
<<<<<<< HEAD
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayMonster();

        std::string sortie = oss.str();

        // Vérifier si la sortie contient "M" et la couleur rouge
        REQUIRE(sortie.find("M") != std::string::npos);
        REQUIRE(sortie.find(display::RED) != std::string::npos);
=======
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        objetAffichage.displayMonster();

        std::string sortie = buffer.str();
        REQUIRE_EQ(sortie, "M");
>>>>>>> origin/josh

        std::cout.rdbuf(old);
    }

    SUBCASE("Test de displayBlindMonster()")
    {
<<<<<<< HEAD
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayBlindMonster();

        std::string sortie = oss.str();

        // Vérifier si la sortie contient "W" et la couleur violette
        REQUIRE(sortie.find("W") != std::string::npos);
        REQUIRE(sortie.find(display::PURPLE) != std::string::npos);

        std::cout.rdbuf(old);
    }

    SUBCASE("Test de displayAmulet()")
    {
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayAmulet();

        std::string sortie = oss.str();

        // Vérifier si la sortie contient "A" et la couleur cyan
        REQUIRE(sortie.find("A") != std::string::npos);
        REQUIRE(sortie.find(display::CYAN) != std::string::npos);
=======
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        objetAffichage.displayBlindMonster();

        std::string sortie = buffer.str();
        REQUIRE_EQ(sortie, "m");
>>>>>>> origin/josh

        std::cout.rdbuf(old);
    }

    SUBCASE("Test de displayWall()")
    {
<<<<<<< HEAD
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayWall();

        std::string sortie = oss.str();

        // Vérifier si la sortie contient "#" et la couleur noire
        REQUIRE(sortie.find("#") != std::string::npos);
        REQUIRE(sortie.find(display::BLACK) != std::string::npos);
=======
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        objetAffichage.displayWall();

        std::string sortie = buffer.str();
        REQUIRE_EQ(sortie, "#");
>>>>>>> origin/josh

        std::cout.rdbuf(old);
    }

    SUBCASE("Test de displayEmptyCase()")
    {
<<<<<<< HEAD
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayEmptyCase();

        std::string sortie = oss.str();

        // Vérifier si la sortie contient un espace (case vide)
        REQUIRE(sortie.find(" ") != std::string::npos);
=======
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        objetAffichage.displayEmptyCase();

        std::string sortie = buffer.str();
        REQUIRE_EQ(sortie, "_");
>>>>>>> origin/josh

        std::cout.rdbuf(old);
    }

    SUBCASE("Test de displayExternCase()")
    {
<<<<<<< HEAD
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayExternCase();

        std::string sortie = oss.str();

        // Vérifier si la sortie contient "X" et la couleur verte
        REQUIRE(sortie.find("X") != std::string::npos);
        REQUIRE(sortie.find(display::GREEN) != std::string::npos);
=======
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        objetAffichage.displayExternCase();

        std::string sortie = buffer.str();
        REQUIRE_EQ(sortie, "X");
>>>>>>> origin/josh

        std::cout.rdbuf(old);
    }

    SUBCASE("Test de displayCoin()")
    {
<<<<<<< HEAD
        std::ostringstream oss;
        std::streambuf* old = std::cout.rdbuf(oss.rdbuf());

        objetAffichage.displayCoin();

        std::string sortie = oss.str();

        // Vérifier si la sortie contient "O" et la couleur jaune
        REQUIRE(sortie.find("O") != std::string::npos);
        REQUIRE(sortie.find(display::YELLOW) != std::string::npos);

        std::cout.rdbuf(old);
    }
}
=======
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        objetAffichage.displayCoin();

        std::string sortie = buffer.str();
        REQUIRE_EQ(sortie, "o");

        std::cout.rdbuf(old);
    }
}
>>>>>>> origin/josh
