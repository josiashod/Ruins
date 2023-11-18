#include <sstream>
#include"doctest.h"
#include "point.h"

TEST_CASE("[point] Les points sont bien construits et que les Getter nous renvoyent les coordonnees")
{
    SUBCASE("constructeur par defaut") {
        point p{};
        int nul=0;
        REQUIRE_EQ(p.x(), nul);
        REQUIRE_EQ(p.y(), nul);
    }
    SUBCASE("constructeur avec valeur")
    {
        int x=2;
        int y=3;
        point p{x,y};
        REQUIRE_EQ(p.x(), x);
        REQUIRE_EQ(p.y(), y);
    }
}
TEST_CASE("[point] Les replacement des points ")
{
    SUBCASE("modification de la position")
    {
        int x=2,y=3;
        point p{};
        p.moveOn(x,y);
        REQUIRE_EQ(p.x(), x);
        REQUIRE_EQ(p.y(), y);
    }
    SUBCASE("modification de la position à l'aide de coeficient")
    {
        point p{1,2};
        p.moveOff(1,1);
        REQUIRE(p.x()== 2);
        REQUIRE(p.y()== 3);
    }
}
TEST_CASE("[point] Les surcharges des operateurs concernant les points ")
{
    SUBCASE("[point] Les surcharges des operateurs de test d'égaliter")
    {
        SUBCASE("[point] la surcharge  == ")
        {
            point p1{1,2};
            point p2{1,2};
            REQUIRE_EQ(p1, p2);

        }
        SUBCASE("[point] La surcharge  =!= ")
        {
            point p1{1,2};
            point p2{3,2};
            REQUIRE_NE(p1, p2);
        }
    }
    SUBCASE("[point] Les surcharges de +=")
    {
        point p1{1,2};
        point p2{3,2};
        point p3=p1;
        p1+=p2;
        REQUIRE_EQ(p1.x(),p2.x()+p3.x());
        REQUIRE_EQ(p1.y(),p2.y()+p3.y());
    }
    SUBCASE("[point] Les surcharges de -=")
    {
        point p1{2,2};
        point p2{1,1};
        point p3=p1;
        p1-=p2;
        REQUIRE_EQ(p1.x(),p3.x()-p2.x());
        REQUIRE_EQ(p1.y(),p3.y()-p2.y());
    }
    SUBCASE("[point] Les surcharges de =")
    {
        point p1{2,2};
        point p3=p1;
        REQUIRE_EQ(p3.x(),p1.x());
        REQUIRE_EQ(p3.y(),p1.y());
    }
}

/*
TEST_CASE("Test de l'opérateur << pour MyClass") {
    point p1{2,2};
    // Créez un ostringstream pour capturer la sortie du flux.
    std::ostringstream output;

    // Utilisez l'opérateur << pour écrire dans le std::ostringstream.
    output << p1;

    // Comparez la sortie générée avec la sortie attendue.
    CHECK(output.str() == "[2,2]");
}
*/