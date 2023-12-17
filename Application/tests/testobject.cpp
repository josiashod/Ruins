#include "doctest.h"
#include "../components/header/object.h"

<<<<<<< HEAD
TEST_CASE("[object] Constructions et modifications du points de solidité d'un objet")
{
    SUBCASE("construction d'un object")
    {
        object o{100};

=======
TEST_CASE("[object] Constructions et modifications du points de solidité d'un objet") {
    SUBCASE("construction d'un object") {
        object o{100};
>>>>>>> origin/David
        // Vérification de la valeur retouner
        REQUIRE_EQ(o.solidity(), 100);
    }

<<<<<<< HEAD
    SUBCASE("Reuction et augmentation du point de solidité")
    {
        SUBCASE("test de la reduction")
        {
=======
    SUBCASE("Reuction et augmentation du point de solidité") {
        SUBCASE("test de la reduction") {
>>>>>>> origin/David
            object o{100};

            o.reduce(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.reduce(10);
            REQUIRE_EQ(o.solidity(), 90);
        }
<<<<<<< HEAD
        SUBCASE("test de l'augementation")
        {
=======
        SUBCASE("test de l'augementation") {
>>>>>>> origin/David
            object o{100};

            o.increase(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.increase(10);
            REQUIRE_EQ(o.solidity(), 110);
        }
<<<<<<< HEAD

=======
>>>>>>> origin/David
    }
}