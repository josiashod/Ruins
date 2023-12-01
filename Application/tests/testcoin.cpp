//
// Created by Daav on 01/12/2023.
//

#include "doctest.h"
#include "../components/header/coin.h"

TEST_SUITE("Vérification de la class coin") {
    SCENARIO("Vérification du construcuteur de coin") {
        GIVEN("Initialisation d'un coin") {
            coin c(100, 2, 1);
            THEN("Test de l'affectation des valeurs") {
                REQUIRE_EQ(c.getX(), 2);
                REQUIRE_EQ(c.getY(), 1);
                REQUIRE_EQ(c.amount(), 100);
            }
        }
    }

    SCENARIO("Vérification du changement de montant") {
        GIVEN("Initialisation d'un coin") {
            coin c(100, 2, 1);
            WHEN("Changement du montant") {
                c.changeAmount(200);
                THEN("Vérification du montant") {
                    REQUIRE_EQ(c.amount(), 200);
                }
            }
        }
    }
}