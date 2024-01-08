//
// Created by Daav on 22/12/2023.
//

#include "doctest.h"
#include "../character.h"
#include "../adventurer.h"
#include "../monster.h"

TEST_SUITE("Test des méthodes de la classe adventurer") {
    TEST_SUITE("Test des constructeurs") {
        SCENARIO("Test du constructeur et des méthodes de récupération") {
            GIVEN("Initialisation d'un aventurier") {
                int swordSolidity = 80, armorSolidity = 20, coins = 5, health = 90, strength = 15;
                std::string type = "adventurer";
                adventurer player(swordSolidity, armorSolidity, coins, health, strength, type);
                THEN("Vérification des données") {
                    REQUIRE_EQ(player.coins(), coins);
                    REQUIRE_EQ(player.health(), health);
                    REQUIRE_EQ(player.strength(), strength);
                    REQUIRE_EQ(player.type(), type);
                }
            }
        }

        SCENARIO("Test du constructeur par défaut et des méthodes de récupération") {
            GIVEN("Initialisation d'un aventurier") {
                adventurer player{};
                THEN("Vérification des données") {
                    REQUIRE_EQ(player.coins(), 0);
                    REQUIRE_EQ(player.health(), 100);
                    REQUIRE_EQ(player.strength(), 10);
                    REQUIRE_EQ(player.type(), "adventurer");
                }
            }
        }
    }

    SCENARIO("Test de l'ajout de pièces") {
        GIVEN("Initialisation d'un aventurier") {
            adventurer player{};
            WHEN("Ajout de pièces") {
                int pieces = 10;
                player.addCoins(pieces);
                THEN("Vérification des pièces ajoutées") {
                    REQUIRE_EQ(player.coins(), pieces);
                }
            }
        }
    }

    TEST_SUITE("Test des méthodes d'attaque, de réception d'attaque et de mort") {
        SCENARIO("Test de la méthode getDamaged") {
            GIVEN("Initialisation d'un aventurier") {
                adventurer player{};
                WHEN("Infligation de dégâts") {
                    int degats = 20;
                    player.getDamaged(degats);
                    THEN("Vérification des données") {
                        REQUIRE_EQ(player.health(), 100 - degats);
                    }
                }
            }
        }
    }
}
