#include "doctest.h"
#include "../components/header/equipement.h"

TEST_CASE("[equipement] Constructions et modifications du points de solidité d'un objet") {
    SUBCASE("construction d'un equipement") {
        equipement o{100};
        // Vérification de la valeur retouner
        REQUIRE_EQ(o.solidity(), 100);
    }

    SUBCASE("Reuction et augmentation du point de solidité")
    {
        SUBCASE("test de la reduction")
        {
            equipement o{100};

            o.reduce(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.reduce(10);
            REQUIRE_EQ(o.solidity(), 90);
        }
        SUBCASE("test de l'augementation")
        {
            equipement o{100};

            o.increase(-10);
            REQUIRE_EQ(o.solidity(), 100);
            o.increase(10);
            REQUIRE_EQ(o.solidity(), 110);
        }
    }
}