//
// Created by Daav on 18/11/2023.
//

#include <cstdlib>
#include "blindMonster.h"

blindMonster::blindMonster() : monster{'B', "Monstre Aveugle"} {}

void blindMonster::move() {
    // Déclaration des variables de coordonnées
    int X, Y;

    do {
        // Génération d'un nombre aléatoire entre -1 et 1 pour le déplacement horizontal
        X = rand() % 3 - 1;
        // Génération d'un nombre aléatoire entre -1 et 1 pour le déplacement vertical
        Y = rand() % 3 - 1;
    } while(X == 0 && Y == 0); // Nouvelle génération si les deux sont nuls car le monstre doit bouger

    // Déplcament du monstre
    d_position.moveOn(X,Y);
}