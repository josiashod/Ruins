//
// Created by Arthur Mathis on 20/11/2023.
//
#include "doctest.h"
<<<<<<< HEAD
#include "../components/header/point.h"
=======
#include "../components/header/coord.h"
#include "../components/header/adventurer.h"
#include "../components/header/monster.h"
>>>>>>> origin/David
#include "../components/header/blindMonster.h"

TEST_SUITE("Vérification de la class blindMonster"){
    SCENARIO("Vérification de la class character") {
        GIVEN("Initialisation d'un blindMonster") {
            blindMonster bm{};
            THEN("Test des points de vie et de la force d'attaque") {
<<<<<<< HEAD
                REQUIRE_EQ(bm.healthPoints(), 100);
                REQUIRE_EQ(bm.strengthPoints(), 10);
=======
                REQUIRE_EQ(bm.health(), 90);
                REQUIRE_EQ(bm.strength(), 5);
>>>>>>> origin/David
            }
        }
    }

    TEST_SUITE("Vérification des constructeurs de la classe blindMonster"){
        SCENARIO("Test du constructeur par défault"){
            GIVEN("Initialisation d'un blindMonster"){
                blindMonster bm{};
                THEN("Test des données de base"){
<<<<<<< HEAD
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
                blindMonster bm{healthPoints, strenghtPoints, hability};
                THEN("Test du symbole, de la nature, du pourentage d'habilieté, des points de vie et de la force d'attaque"){
                    REQUIRE_EQ(bm.getSymbol(), 'B');
                    REQUIRE_EQ(bm.getNature(), "Monstre Aveugle");
                    REQUIRE_EQ(bm.healthPoints(), healthPoints);
                    REQUIRE_EQ(bm.strengthPoints(), strenghtPoints);
                    REQUIRE_EQ(bm.habilityPercentage(), hability);
=======
                    REQUIRE_EQ(bm.health(), 100);
                    REQUIRE_EQ(bm.strength(), 10);
                    REQUIRE_EQ(bm.hability(), 90);
                }
            }
        }
        SCENARIO("Test du constructeur par valeurs"){
            GIVEN("Initialisation d'un blindMonster"){
                int health = 240, strength = 132;
                double hability = 55;
                blindMonster bm{health, strength, hability};
                THEN("Test du symbole, de la nature, du pourentage d'habilieté, des points de vie et de la force d'attaque"){
                    REQUIRE_EQ(bm.health(), health);
                    REQUIRE_EQ(bm.strength(), strength);
                    REQUIRE_EQ(bm.hability(), hability);
>>>>>>> origin/David
                }
            }
        }
    }

    TEST_SUITE("Vérification des fonctions d'attaque, de défense et de mort"){
<<<<<<< HEAD
        SCENARIO("Test de la fonction getAttacked"){
=======
        SCENARIO("Test de la fonction hasBeenAttacked"){
>>>>>>> origin/David
            GIVEN("Initialisation d'un blindMonster"){
                blindMonster bm{};
                WHEN("Réalisation de l'attaque"){
                    int attaque = 23;
<<<<<<< HEAD
                    bm.getAttacked(attaque);
                    THEN("Attaque réalisée"){
                        REQUIRE_EQ(bm.healthPoints(), 100-23);
=======
                    bm.hasBeenAttacked(attaque);
                    THEN("Attaque réalisée"){
                        REQUIRE_EQ(bm.health(), 100-23);
>>>>>>> origin/David
                    }
                }
            }
        }
<<<<<<< HEAD

=======
>>>>>>> origin/David
        SCENARIO("Test de la fonction attack"){
            GIVEN("Initialisation de deux monsters"){
                blindMonster m1{}, m2{};
                WHEN("Réalisation de l'attaque"){
                    m1.attack(m2);
                    THEN("Attaque réussie"){
<<<<<<< HEAD
                        bool valid {m2.healthPoints() == 100 - m1.strengthPoints() ||
                                    m2.healthPoints() == 100 - 0.9 * m1.strengthPoints()};
=======
                        bool valid {m2.health() == 100 - m1.strength() ||
                                    m2.health() == 100 - 0.9 * m1.strength()};
>>>>>>> origin/David
                        REQUIRE_EQ(valid, true);
                    }
                }
            }
        }
<<<<<<< HEAD

=======
>>>>>>> origin/David
        SCENARIO("Test de la fonction die"){
            GIVEN("Initialisation de deux monsters"){
                blindMonster m1{100, 120, 90}, m2{100,20, 30};
                WHEN("Réalisation de l'attaque"){
                    m1.attack(m2);
                    THEN("Vérification de la mort"){
                        REQUIRE_EQ(m2.isDead(), true);
                    }
                }
            }
        }
    }

    TEST_SUITE("Test des fonctions de déplacement"){
        SCENARIO("vérification du calcul de déplacements aléatoires"){
            int x;
            for(int i = 0; i < 100; i++){
                x = rand() % 3 - 1;
                THEN("Généartion"){
                    bool valid {x >= -1 && x <= 1};
                    REQUIRE_EQ(valid, true);
                }
            }
        }
<<<<<<< HEAD

=======
>>>>>>> origin/David
        SCENARIO("Vérifcation du déplacement"){
            GIVEN("Calcul d'un déplacement et initialisation d'un blindMonster"){
                int x{rand() % 3 - 1}, y{rand() % 3 - 1};
                blindMonster bm{};
                WHEN("Déplacement du blindMonster"){
<<<<<<< HEAD
                    bm.MoveElement(x, y);
                    THEN("Vérification des coordonnées"){
                        REQUIRE_EQ(bm.getX(), x);
                        REQUIRE_EQ(bm.getY(), y);
=======
                    bm.move(x, y);
                    THEN("Vérification des coordonnées"){
                        REQUIRE_EQ(bm.position().x(), x);
                        REQUIRE_EQ(bm.position().y(), y);
                    }
                }
            }
        }
    }
}

TEST_SUITE("Test de monster"){
    TEST_SUITE("Vérification des constructeurs"){
        SCENARIO("Test du constructeur par défaut"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                monster m{1,1,1,p};
                THEN("Test des données de base"){
                    REQUIRE_EQ(m.health(), 100);
                    REQUIRE_EQ(m.strength(), 10);
                    REQUIRE_EQ(m.hability(), 90);
                    REQUIRE_EQ(m.adventurer(), p);
                    delete p;
                }
            }
        }
        SCENARIO("Test du constructeur par valeurs 1"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                int hability = 50;
                monster m{hability, p};
                THEN("Test des données de base"){
                    REQUIRE_EQ(m.health(), 100);
                    REQUIRE_EQ(m.strength(), 10);
                    REQUIRE_EQ(m.hability(), hability);
                    REQUIRE_EQ(m.adventurer(), p);
                    delete p;
                }
            }
        }
        SCENARIO("Test du constructeur par valeurs 2"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                int health = 240, strength = 130;
                double hability = 50;
                monster m{health, strength, hability, p};
                THEN("Test des données de base"){
                    REQUIRE_EQ(m.health(), health);
                    REQUIRE_EQ(m.strength(), strength);
                    REQUIRE_EQ(m.hability(), hability);
                    REQUIRE_EQ(m.adventurer(), p);
                    delete p;
                }
            }
        }
    }

    TEST_SUITE("Test de détection du joueur"){
        SCENARIO("Test de validation de la méthode isClose"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(1,1);
                monster m{p};
                THEN("adventurer positionné"){
                    REQUIRE_EQ(m.isClose(), true);
                    delete p;
                }
            }
        }
        SCENARIO("Test de non validation de la méthode isClose"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(12,13);
                monster m{p};
                THEN("adventurer positionné") {
                    REQUIRE_EQ(m.isClose(), false);
                    delete p;
                }
            }
        }
    }

    TEST_SUITE("Test de déplacement vers le joueur"){
        SCENARIO("Vérification de la méthode direction 1"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(1,0);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 1);
                        delete p;
                    }
                }
            }
        }
        SCENARIO("Vérification de la méthode direction 2"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(1,2);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 2);
                        delete p;
                    }
                }
            }
        }
        SCENARIO("Vérification de la méthode direction 3"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(2,1);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 3);
                        delete p;
                    }
                }
            }
        }
        SCENARIO("Vérification de la méthode direction 4"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(0,1);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 4);
                        delete p;
                    }
                }
            }
        }
        SCENARIO("Vérification de la méthode direction 5"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(0,0);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 5);
                        delete p;
                    }
                }
            }
        }
        SCENARIO("Vérification de la méthode direction 6"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(2,0);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 6);
                        delete p;
                    }
                }
            }
        }
        SCENARIO("Vérification de la méthode direction 7"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(0,2);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 7);
                        delete p;
                    }
                }
            }
        }
        SCENARIO("Vérification de la méthode direction 8"){
            GIVEN("Initialisation d'un monster"){
                adventurer *p{new adventurer{}};
                p->move(2,2);
                WHEN("adventurer positionné"){
                    monster m{p};
                    m.move(1,1);
                    THEN("Monstre positionné"){
                        REQUIRE_EQ(m.direction(), 8);
                        delete p;
>>>>>>> origin/David
                    }
                }
            }
        }
    }
}