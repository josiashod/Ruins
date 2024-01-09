
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





TEST_SUITE("Test longueurAS")
{
    SECTION("test de ajoute(pouces)")
    {
    int pieds {4}, pouces {6};
    longueurAS longueur {pieds, pouces};
    SECTION("Ajoute 0 pouces")
        {
        longueur.ajoute(0);
        REQUIRE_EQ(longueur.pieds(), pieds);
        REQUIRE_EQ(longueur.pouces(), pouces);
        }
    SECTION("Nombre total de pouces <12")
        {
        int poucesAjoutes {12-pouces-2};
        int totalPouces { longueur.pouces()+poucesAjoutes };
        longueur.ajoute(poucesAjoutes);
        REQUIRE_EQ(longueur.pieds(), pieds);
        REQUIRE_EQ(longueur.pouces(), totalPouces);
        }
        SECTION("Nombre total de pouces >12")
        {
        int poucesAjoutes {12-pouces+22};
        longueur.ajoute(poucesAjoutes);
        int totalPouces { longueur.pouces()+poucesAjoutes };
        REQUIRE_EQ(longueur.pieds(), pieds+totalPouces/12);
        REQUIRE_EQ(longueur.pouces(), totalPouces%12);
    }

        SECTION("Nombre total de pouces =12")
        {
        int poucesAjoutes {12-pouces};
        longueur.ajoute(poucesAjoutes);
        REQUIRE_EQ(longueur.pieds(), pieds+1);
        REQUIRE_EQ(longueur.pouces(), 0);
        }
    }
}

constexpr int TypeDortoir=0;
constexpr int TypeChambre =1;
constexpr double PrixPremiereNuitDortoir=30;
constexpr double PrixNuitDortoir =25;
constexpr double PrixNuitChambre =40;
constexpr double TaxeSejourBase =1.1;


string genfac(int n, int typeChambre)
{
    string Facture= "Facture du séjour de " + to_string(n) + " nuits\n";
    if (typeChambre == TypeDortoir)
    { //hébergement dortoir
        double prixFacture=PrixPremiereNuitDortoir+PrixNuitDortoir*(n-1);
        Double PrixTaxe=n*TaxeSejourBase;
    }
    else
    {
        double prixFacture=PrixNuitChambre*(n-1);
        Double PrixTaxe=n*TaxeSejourBase*2;
    }

    





//première nuit 30 EUR, nuits suivantes 25 EUR la nuit
    double prixFacture=PrixPremiereNuitDortoir+PrixNuitDortoir*(n-1);
        Facture += "Prix hébergement : " + to_string(prixFacture) + ’\n’;

//taxe séjour : taxe de base (1,1 EUR par jour )

        Facture += "Prix taxe séjour : " + to_string(PrixTaxe) + ’\n’;
        Facture += "Prix total : " + to_string(PrixTaxe+prixFacture) + ’\n’;
    }
//40 EUR par nuit
        f += "Prix hébergement : " + to_string(n*40) + ’\n’;
//taxe : deux fois la taxe de base (1.1 EUR par jour )
        f += "Prix taxe séjour : " + to_string(2.2*n) + ’\n’;
        f += "Prix total : " + to_string(2.2*n+n*40)) + ’\n’;
    }
return f;
}

