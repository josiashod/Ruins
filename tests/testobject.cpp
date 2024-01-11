#include "doctest.h"
<<<<<<< HEAD:Application/tests/testobject.cpp
#include "../components/header/object.h"

TEST_CASE("[object] Constructions et modifications du points de solidité d'un objet") {
    SUBCASE("construction d'un object") {
        object o{100};
=======
#include "../equipment.h"

TEST_CASE("[equipment] Constructions et modifications du points de solidité d'un objet") {
    SUBCASE("construction d'un equipment") {
        equipment o{100};
>>>>>>> origin/David:tests/testobject.cpp
        // Vérification de la valeur retouner
        REQUIRE_EQ(o.solidity(), 100);
    }

<<<<<<< HEAD:Application/tests/testobject.cpp
    SUBCASE("Reuction et augmentation du point de solidité") {
        SUBCASE("test de la reduction") {
            object o{100};
=======
    SUBCASE("Reuction et augmentation du point de solidité")
    {
        SUBCASE("test de la reduction")
        {
            equipment o{100};
>>>>>>> origin/David:tests/testobject.cpp

            o.reduce(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.reduce(10);
            REQUIRE_EQ(o.solidity(), 90);
        }
<<<<<<< HEAD:Application/tests/testobject.cpp
        SUBCASE("test de l'augementation") {
            object o{100};
=======
        SUBCASE("test de l'augementation")
        {
            equipment o{100};
>>>>>>> origin/David:tests/testobject.cpp

            o.increase(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.increase(10);
            REQUIRE_EQ(o.solidity(), 110);
        }
    }
}