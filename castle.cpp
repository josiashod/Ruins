//
// Created by Daav on 19/12/2023.
//

#include "castle.h"
#include "blindMonster.h"

string castle::typeCode(const box &box) const {
    // Initialisation d'une variable pour stocker le code
    string code;

    // Vérifie le type de la case
    if(box.type() == box::BX_WALL) {
        // Si c'est un mur, le code est W
        code = "W";
    } else if(box.type() == box::BX_EXTERN) {
        // Si c'est une case externe, le code est E
        code = "E";
    } else if(box.type() == box::BX_ACCESSIBLE) {
        // Si c'est une case accessible, on vérifie son contenu pour déterminer le code
        if(box.hasCoins())
            // Si elle contient des pièces, le code est C suivi du nombre de pièces
            code = "C" + std::to_string(box.coins());
        else if(box.hasAmulet())
            // Si elle a une amulette, le code est A
            code = "A";
        else if(box.getCharacter() == nullptr)
            // Si elle est vide, le code est R
            code = "R";
        else if(box.getCharacter()->type() == character::CHAR_ADVENTURER)
            // Si elle contient un aventurier, le code est P
            code = "P";
        else if(box.getCharacter()->type() == character::CHAR_MONSTER)
            // Si elle contient un monstre, le code est M
            code = "M";
        else if(box.getCharacter()->type() == character::CHAR_BLINDMONSTER)
            // Si elle contient un monstre aveugle, le code est B
            code = "B";
    }

    // Renvoi du code représentant le type de la case
    return code;
}

box castle::boxFromType(const string &type, std::shared_ptr<adventurer> &adventurer, vector<std::shared_ptr<monster>> &monsters, int i, int j) const {
    int coins = 0; // Initialisation du nombre de pièces
    bool amulet = false; // Initialisation de la présence d'une amulette
    character* c = nullptr; // Initialisation d'un pointeur de personnage à nullptr

    // Vérifie le type de case passé en paramètre et crée la case correspondante
    if(type == "W") {
        // Si le type est un mur, on retourne une case de type mur
        return box(box::BX_WALL);
    } else if(type == "E") {
        // Si le type est une case externe, on retourne une case de type externe
        return box(box::BX_EXTERN);
    } else if(type[0] == 'C') {
        // Si le type commence par C, on extrait le nombre de pièces du code
        coins = stoi(type.substr(1));
        // Retourner une case accessible avec le nombre de pièces extrait
        return box(box::BX_ACCESSIBLE, coins);
    } else if(type == "A") {
        // Si le type est A, on retourne une case accessible avec une amulette
        return box(box::BX_ACCESSIBLE, 0, true);
    } else if(type == "R") {
        // Si le type est R, on retourne une case accessible vide
        return box(box::BX_ACCESSIBLE);
    } else if(type == "P") {
        // Si le type est P, on crée un nouvel aventurier par défaut
        adventurer->move(i,j);
        // Réinitialiser l'aventurier
        adventurer->reset();
        // Retourner une case accessible avec l'aventurier créé
        return box(box::BX_ACCESSIBLE, 0, false, adventurer);
    } else if(type == "M") {
        // Si le type est M, on crée un nouveau monstre voyant par défaut
        std::shared_ptr<monster> m = std::make_shared<monster>();
        m->character::move(i,j);
        m->reset();
        monsters.push_back(std::move(m));
        // Retourner une case accessible avec le monstre voyant créé
        return box(box::BX_ACCESSIBLE, 0, false, monsters.back());
    } else if(type == "B") {
        // Si le type est B, on crée un nouveau monstre aveugle
        std::shared_ptr<blindMonster> m = std::make_shared<blindMonster>();
        m->character::move(i,j);
        m->reset();
        monsters.push_back(std::move(m));
        // Retourner une case accessible avec le monstre aveugle créé
        return box(box::BX_ACCESSIBLE, 0, false, monsters.back());
    }
}

void castle::init(std::shared_ptr<adventurer> &adventurer, vector<std::shared_ptr<monster>> &monsters) {
    // On charge la map de base
    load("./defaultCastle.txt", adventurer, monsters);
}

void castle::save(const string &filename) {
    // Ouverture du fichier
    std::ofstream file(filename);

    // Vérification de l'ouverture du fichier
    if(file) {
        // On parcourt chaque ligne de cases dans la grille du château
        for(const auto& row : d_boxes) {
            // On parcourt chaque case dans une ligne de la grille
            for(const auto& box : row)
                // On écrit le code correspondant au type de la boîte suivi d'un espace
                file << typeCode(box) << " ";
            // On saute une ligne après avoir écrit toutes les cases d'une ligne
            file << std::endl;
        }
        // Fermeture du fichier
        file.close();
    } else
        // Si le fichier n'a pas pu être ouvert, on envoie un message d'erreur
        std::cout << "Le fichier suivant n'a pas pu être sauvegardé : " << filename << std::endl;
}

bool castle::load(const string &filename, std::shared_ptr<adventurer> &adventurer, vector<std::shared_ptr<monster>> &monsters) {
    // Ouverture du fichier
    std::ifstream file(filename);

    // Vérification de l'ouverture du fichier
    if(file.is_open()) {
        // On vide le tableau contenant la grille
        d_boxes.clear();

        string line;
        int i = 0;
        // On parcourt chaque ligne du fichier représentant une ligne de cases dans la grille du château
        while(std::getline(file, line)) {
            int j = 0;
            // On crée un flux pour lire chaque code de case dans une ligne
            std::istringstream iss(line);
            // On stocke les cases d'une ligne de la grille
            vector<box> row;

            string code;
            // On parcourt chaque code de case dans une ligne de la grille
            while(iss >> code) {
                // On crée une case à partir du code et on l'ajoute à la ligne
                row.push_back(boxFromType(code, adventurer, monsters, i, j));
                j++;
            }

            // On ajoute la ligne complète à la grille du château
            d_boxes.push_back(row);
            i++;
        }

        // Fermeture du fichier
        file.close();
        return true;
    } else {
        // Si le fichier n'a pas pu être ouvert, on envoie un message d'erreur
        std::cout << "Le fichier suivant n'a pas pu être chargé : " << filename << std::endl;
        std::cout << "Veuillez vérifier le nom du fichier." << std::endl << std::endl;
        return false;
    }
}