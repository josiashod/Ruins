#include "doctest.h"
#include "../components/header/object.h"

TEST_CASE("[object] Constructions et modifications du points de solidité d'un objet")
{
    SUBCASE("construction d'un object")
    {
        object o{100};

        // Vérification de la valeur retouner
        REQUIRE_EQ(o.solidity(), 100);
    }

    SUBCASE("Reuction et augmentation du point de solidité")
    {
        SUBCASE("test de la reduction")
        {
            object o{100};

            o.reduce(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.reduce(10);
            REQUIRE_EQ(o.solidity(), 90);
        }
        SUBCASE("test de l'augementation")
        {
            object o{100};

            o.increase(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.increase(10);
            REQUIRE_EQ(o.solidity(), 110);
        }

    }
}