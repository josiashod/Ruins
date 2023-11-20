//
// Created by Arthur Mathis on 20/11/2023.
//
#include "doctest.h"
#include "../components/header/point.h"
#include "../components/header/blindMonster.h"

TEST_SUITE("Vérification de la class blindMonster"){
    SCENARIO("Vérification de la class character") {
        GIVEN("Initialisation d'un blindMonster") {
            point p{};
            blindMonster bm{};
            THEN("Test des points de vie et de la force d'attaque") {
                REQUIRE_EQ(bm.healthPoints(), 100);
                REQUIRE_EQ(bm.strengthPoints(), 10);
            }
        }
    }

    TEST_SUITE("Vérification des constructeurs de la classe blindMonster"){
        SCENARIO("Test du constructeur par défault"){
            GIVEN("Initialisation d'un blindMonster"){
                point p{};
                blindMonster bm{};
                THEN("Test des données de base"){
                    REQUIRE_EQ(bm.getSymbol(), 'B');
                    REQUIRE_EQ(bm.getNature(), "Monstre Aveugle");
                    REQUIRE_EQ(bm.healthPoints(), 100);
                    REQUIRE_EQ(bm.strengthPoints(), 10);
                    REQUIRE_EQ(bm.habilityPercentage(), 90);
                }
            }
        }

        SCENARIO("Test du constructeur par valeurs"){
            GIVEN("Initialisation d'un blindMonster"){
                int healthPoints = 240, strenghtPoints = 132, hability = 55;
                point p{};
                blindMonster bm{healthPoints, strenghtPoints, hability};
                THEN("Test du symbole, de la nature, du pourentage d'habilieté, des points de vie et de la force d'attaque"){
                    REQUIRE_EQ(bm.getSymbol(), 'B');
                    REQUIRE_EQ(bm.getNature(), "Monstre Aveugle");
                    REQUIRE_EQ(bm.healthPoints(), healthPoints);
                    REQUIRE_EQ(bm.strengthPoints(), strenghtPoints);
                    REQUIRE_EQ(bm.habilityPercentage(), hability);
                }
            }
        }
    }

    SCENARIO("Test de la fonction getAttacked"){
        GIVEN("Initialisation d'un blindMonster"){
            point p{};
            blindMonster bm{};
            WHEN("Réalisation de l'attaque"){
                int attaque = 23;
                bm.getAttacked(attaque);
                THEN("Attaque réalisée"){
                    REQUIRE_EQ(bm.healthPoints(), 100-23);
                }
            }
        }
    }
}