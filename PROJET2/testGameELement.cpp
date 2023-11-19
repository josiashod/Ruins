#include "doctest.h"
#include "GameElement.h"

/**
 * @file
 * @brief Fichier de tests pour la classe GameElement.
 */

/**
 * @brief Teste la construction des GameElement et la récupération des informations avec les getters.
 */
TEST_CASE("[GameElement] Les GameElement sont bien construits et test sur les Setter les Getter")
{
    SUBCASE("constructeur avec valeur et setter")
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
        REQUIRE_EQ(elt.GetPosition(), pos);
    }
    SUBCASE("test des setter")
    {
        SUBCASE("test des modificateur de position à l'aide d'un point")
        {
            char symbole = 'c';


            point pelt{1, 1};

            point pos{2, 2};

            std::string nature = "Mur";

            GameElement elt{symbole, pelt, nature};
            elt.MoveElement(pos);

            REQUIRE_EQ(elt.getX(), pos.x());
            REQUIRE_EQ(elt.getY(), pos.y());
        }
        SUBCASE("test des modificateur de position à l'aide d'entier")
        {
            char symbole = 'c';
            point pos{1, 1};
            int x=2,y=2;
            std::string nature = "Mur";
            GameElement elt{symbole, pos, nature};
            elt.MoveElement(x,y);

            REQUIRE_EQ(elt.getX(), x);
            REQUIRE_EQ(elt.getY(), y);
        }

    }
}