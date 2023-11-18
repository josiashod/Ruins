#include "doctest.h"
#include "GameElement.h"

/**
 * @file
 * @brief Fichier de tests pour la classe GameElement.
 */

/**
 * @brief Teste la construction des GameElement et la récupération des informations avec les getters.
 */
TEST_CASE("[GameElement] Les GameElement sont bien construits et que les Getter nous renvoyent les informations sur le GameElement")
{
    SUBCASE("constructeur avec valeur")
    {
        // Définir les valeurs initiales
        char symbole = 'c';
        point pos{1, 1};
        std::string nature = "Mur";

        // Créer un GameElement avec les valeurs définies
        GameElement elt{symbole, pos, nature};

        // Vérifier que les getters renvoient les bonnes informations
        REQUIRE_EQ(elt.getX(), pos.x());
        REQUIRE_EQ(elt.getY(), pos.y());
        REQUIRE_EQ(elt.getSymbol(), symbole);
        REQUIRE_EQ(elt.getNature(), nature);
    }
}