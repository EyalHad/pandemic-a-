#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"


using namespace pandemic;

#include <iostream>

using namespace std;


#include "Color.hpp"
#include "City.hpp"

TEST_CASE("GAME"){

    Board b1;


    SUBCASE("Researcher Role"){

        Researcher david(b1,City::Washington);

        b1[City::Algiers] = 5;
        b1[City::Atlanta] = 4;
        b1[City::Bangkok] = 3;
        b1[City::BuenosAires] = 2;
        b1[City::Delhi] = 1;

        david.take_card(City::Tokyo) 
            .take_card(City::Washington) 
            .take_card(City::Istanbul)
            .take_card(City::Karachi)
            .take_card(City::Kolkata)
            .take_card(City::Kolkata) // Will do nothing
            .take_card(City::Moscow);

        /** 
         * 1 RED
         * 1 BLUE
         * 4 BLACK
         * 0 YELLOW
         */

        CHECK_THROWS(david.discover_cure(Color::Black)); // Have only 4 Black Cards

        david.take_card(City::Algiers); // Now we have 5 Black Cards

        CHECK_NOTHROW(david.discover_cure(Color::Black));

        /** 
         * 1 RED
         * 1 BLUE
         * 0 BLACK
         * 0 YELLOW
         */

        david.build(); // Build A Station in Washington

        david.take_card(City::Algiers);
        CHECK_NOTHROW(david.fly_direct(City::Algiers));

        CHECK_NOTHROW(david.treat()); // Need to reduce to ZERO there is a Black cure

        CHECK_THROWS(david.treat()); // When using treat on ZERO level it is illegal
        CHECK_THROWS(david.drive(City::Tokyo)); // We Have the right Card (Also irrelevant) but we are not on a neighbor City

        david.take_card(City::Atlanta)
            .take_card(City::London)
            .take_card(City::Milan)
            .take_card(City::Madrid)
            .take_card(City::Delhi)
            .take_card(City::Bangkok)
            .take_card(City::BuenosAires);

        /** 
         * 2 RED
         * 5 BLUE
         * 1 BLACK
         * 1 YELLOW
         */    

        CHECK_NOTHROW(david.discover_cure(Color::Blue));

        /** 
         * 2 RED
         * 0 BLUE
         * 1 BLACK
         * 1 YELLOW
         */

        david.take_card(City::Atlanta);
        CHECK_NOTHROW(david.fly_direct(City::Atlanta));
        CHECK_NOTHROW(david.treat());


        CHECK_THROWS(david.fly_direct(City::Kolkata)); // We had it but not anymore
        CHECK_NOTHROW(david.fly_direct(City::Bangkok));
        CHECK_NOTHROW(david.treat());

        david.take_card(City::Bogota);
        CHECK_NOTHROW(david.fly_direct(City::Bogota));
        CHECK_NOTHROW(david.drive(City::BuenosAires));

        CHECK_NOTHROW(david.treat());
        CHECK_NOTHROW(david.treat());
        CHECK_THROWS(david.treat()); // When using treat on ZERO level it is illegal


        CHECK_FALSE(b1.is_clean());

        CHECK_NOTHROW(david.fly_direct(City::Delhi));
        CHECK_NOTHROW(david.treat());

        CHECK(b1.is_clean() == true);

    }
    SUBCASE("OperationsExpert Role"){


        b1[City::Montreal] = 1;
        b1[City::Atlanta] = 1;


        OperationsExpert shlomo(b1,City::SanFrancisco);

        CHECK_NOTHROW(shlomo.build()); // Station in SanFrancisco
        CHECK_NOTHROW(shlomo.drive(City::Chicago)); 

        CHECK_NOTHROW(shlomo.build()); // Station in Chicago
        CHECK_THROWS(shlomo.treat()); // There Are no disease here...

        CHECK_NOTHROW(shlomo.drive(City::Montreal));
        CHECK_NOTHROW(shlomo.treat());
        CHECK_THROWS(shlomo.treat()); // When ZERO we throw !

        CHECK_THROWS(shlomo.drive(City::Montreal)); // We already here :)
        CHECK_NOTHROW(shlomo.build()); // Station in Montreal

        CHECK_NOTHROW(shlomo.fly_shuttle(City::Chicago)); // Back to Chicago using flight, we can cuz of Station
        CHECK_THROWS(shlomo.drive(City::Atlanta));

        CHECK_NOTHROW(shlomo.build()); // Station in Atlanta

        shlomo.take_card(City::Jakarta)
            .take_card(City::Atlanta);

        CHECK_NOTHROW(shlomo.fly_direct(City::Jakarta)); // Flying very far on the Map :)
        CHECK_NOTHROW(shlomo.build()); // Station in Jakarta

        CHECK_NOTHROW(shlomo.fly_shuttle(City::Atlanta)); // Back to Atlanta using flight, we can cuz of Station

        CHECK_FALSE(b1.is_clean());

        CHECK_NOTHROW(shlomo.treat());
        CHECK_THROWS(shlomo.treat()); // When ZERO we throw !

        CHECK(b1.is_clean() == true);


    }
    SUBCASE("Dispatcher Role"){

        /**
         * In this Sub Case We are going to check mostly how to these two above can work toghether
         * and beat the game very easily
         */

        OperationsExpert shlomo(b1,City::SanFrancisco);
        Dispatcher moshe(b1,City::SanFrancisco);

        // Shlomo will not take any cards and they will beat the game

        b1[City::Algiers] = 5;
        b1[City::Delhi] = 5;
        b1[City::Tehran] = 5;


        moshe.take_card(City::Algiers)
        .take_card(City::Baghdad)
        .take_card(City::Cairo)
        .take_card(City::Chennai)
        .take_card(City::Delhi);
        

        CHECK_NOTHROW(shlomo.build()); // Station in SanFrancisco
        // shlomo did his part and finish playing :)
        CHECK_NOTHROW(moshe.discover_cure(Color::Black)); // Now moshe the Dispatcher can cure all Black with 1 treat

        moshe.take_card(City::SanFrancisco);

        CHECK_NOTHROW(moshe.fly_direct(City::Algiers)); // Flying To use Treat 
        CHECK_NOTHROW(moshe.treat()); 
        CHECK_THROWS(moshe.treat()); // When ZERO we throw !

        CHECK_NOTHROW(moshe.fly_direct(City::SanFrancisco)); //Come back to use his abilty

        moshe.take_card(City::SanFrancisco);

        CHECK_NOTHROW(moshe.fly_direct(City::Delhi)); // Flying To use Treat 
        CHECK_NOTHROW(moshe.treat()); 
        CHECK_THROWS(moshe.treat()); // When ZERO we throw !

        CHECK_NOTHROW(moshe.fly_direct(City::SanFrancisco)); //Come back to use his abilty

        moshe.take_card(City::SanFrancisco);

        CHECK_NOTHROW(moshe.fly_direct(City::Tehran)); // Flying To use Treat 
        CHECK_NOTHROW(moshe.treat()); 
        CHECK_THROWS(moshe.treat()); // When ZERO we throw !

        // He can stay over there cuz he cleared the game from all diseases

        CHECK(b1.is_clean() == true);
        CHECK_THROWS(b1[City::Lagos] = -2);
        
    }

    SUBCASE("Scientist Role"){

        Scientist dana(b1,City::Shanghai,5);
        // This make the character with no special ablities
        Scientist levana(b1,City::Shanghai,2);

        b1[City::Bangkok] = 3;
        CHECK_THROWS(b1[City::Lagos] = -2);

        dana.take_card(City::Shanghai)
        .take_card(City::Sydney)
        .take_card(City::Tokyo)
        .take_card(City::Beijing)
        .take_card(City::Bangkok);

        CHECK_NOTHROW(dana.build());

        dana.take_card(City::Shanghai);

        CHECK_THROWS(dana.discover_cure(Color::Yellow)); // She can discover RED
        CHECK_NOTHROW(dana.discover_cure(Color::Red)); // She did it !

        CHECK_THROWS(dana.drive(City::Bangkok)); // Cant yet ! Not close enaf :)

        CHECK_NOTHROW(dana.drive(City::HongKong));
        CHECK_NOTHROW(dana.drive(City::Bangkok)); // She arrived to the city that has disease

        CHECK_NOTHROW(dana.treat());
        CHECK_THROWS(dana.treat()); // ZERO already

        CHECK_FALSE(b1[City::Bangkok] == 3);

        levana.take_card(City::Chicago)
        .take_card(City::Atlanta)
        .take_card(City::Essen);

        b1[City::Chicago] = 3;

        CHECK_THROWS(levana.drive(City::Chicago)); // Too Far...
        CHECK_NOTHROW(levana.fly_direct(City::Chicago)); // Now we lost the card we are not Dispatcher :)

        levana.take_card(City::Chicago); // Got it back

        CHECK_NOTHROW(levana.build());
        CHECK_THROWS(levana.build()); // We Do not own the Chicago Card anymore...

        CHECK_NOTHROW(levana.discover_cure(Color::Blue)); // Now we have ZERO Cards 

        CHECK_THROWS(levana.fly_shuttle(City::Montreal)); // Montreal do not have a Research Station
        CHECK_THROWS(levana.fly_direct(City::Bangkok));
        CHECK_THROWS(levana.fly_charter(City::Algiers));
        
        CHECK_NOTHROW(levana.drive(City::Montreal));
        CHECK_THROWS(levana.treat(City::Chicago)); // levana maybe Scientist But not a FieldDoctor

        CHECK_NOTHROW(levana.drive(City::Chicago));
        CHECK_NOTHROW(levana.treat());    

        CHECK_NOTHROW(levana.fly_shuttle(City::Shanghai));

        // They can stay where they are cuz they cleared the game from all diseases

        CHECK(b1.is_clean() == true);

        
    }

    SUBCASE("Medic Role"){

        Medic avraham(b1,City::London);
        Researcher david(b1,City::Miami);
        /**
         * These 2 are also a great Combo
         * One Can Discover Cure with no problem /
         * The other one just traveling the world
         * 
         */

        david.take_card(City::Miami)
        .take_card(City::MexicoCity)
        .take_card(City::Santiago)
        .take_card(City::SaoPaulo)
        .take_card(City::BuenosAires)   // Has 5 Yellows
        .take_card(City::Algiers)
        .take_card(City::Baghdad)
        .take_card(City::Cairo)
        .take_card(City::Chennai)
        .take_card(City::Delhi)         // Has 5 Black
        .take_card(City::Essen)
        .take_card(City::London)
        .take_card(City::Chicago)
        .take_card(City::Madrid)
        .take_card(City::Montreal)      // Has 5 Blue
        .take_card(City::Jakarta)
        .take_card(City::HongKong)
        .take_card(City::Bangkok)
        .take_card(City::Beijing)
        .take_card(City::Manila);       // Has 5 Red


        b1[City::London] = 18;
        CHECK_NOTHROW(avraham.treat());
        CHECK_THROWS(avraham.treat());

        b1[City::SaoPaulo] = 62;
        b1[City::Khartoum] = 78;
        b1[City::Cairo] = 2;
        b1[City::HoChiMinhCity] = 74;

        CHECK_THROWS(b1[City::Lagos] = -2);

        CHECK_NOTHROW(david.discover_cure(Color::Black));
        CHECK_NOTHROW(david.discover_cure(Color::Red));
        CHECK_NOTHROW(david.discover_cure(Color::Blue));
        CHECK_NOTHROW(david.discover_cure(Color::Yellow));

        CHECK_NOTHROW(avraham.drive(City::Madrid));
        CHECK_THROWS(avraham.drive(City::Lagos));

        CHECK_NOTHROW(avraham.drive(City::SaoPaulo));
        CHECK(b1[City::SaoPaulo] == 0 );
        CHECK_NOTHROW(avraham.drive(City::Lagos));
        CHECK(b1[City::Lagos] == 0 );
        CHECK_NOTHROW(avraham.drive(City::Khartoum));
        CHECK(b1[City::Khartoum] == 0 );
        CHECK_NOTHROW(avraham.drive(City::Cairo));
        CHECK(b1[City::Cairo] == 0 );
        CHECK_THROWS(avraham.treat()); // ZERO ALREADY
        avraham.take_card(City::HoChiMinhCity);

        CHECK_NOTHROW(avraham.fly_direct(City::HoChiMinhCity));

        CHECK(b1.is_clean() == true);


    }  

    SUBCASE("Virologist Role & GeneSplicer Role & FieldDoctor Role"){

        Virologist simha(b1,City::Cairo);
        GeneSplicer itay(b1,City::Osaka);
        FieldDoctor noah(b1,City::Paris);

        itay.take_card(City::Osaka);
        CHECK_NOTHROW(itay.build()); // Osaka has A Research Station !

        itay.take_card(City::Miami)
        .take_card(City::MexicoCity)
        .take_card(City::BuenosAires)    // Has 3 Yellows
        .take_card(City::Algiers)        // Has 1 Black
        .take_card(City::Montreal)      // Has 1 Blue
        .take_card(City::Manila);       // Has 1 Red

        CHECK_NOTHROW(itay.discover_cure(Color::Red));

        b1[City::HoChiMinhCity] = 5;

        simha.take_card(City::HoChiMinhCity);

        CHECK_NOTHROW(simha.treat(City::HoChiMinhCity)); 
        CHECK(b1[City::HoChiMinhCity] == 0);

        CHECK_THROWS(noah.treat(City::HoChiMinhCity)); // Not Close and City Has ZERO diseases !

        b1[City::London] = 6;

        simha.take_card(City::London);

        CHECK_NOTHROW(noah.treat(City::London));

        CHECK(b1[City::London] == 5);

        CHECK_NOTHROW(simha.treat(City::London));

        CHECK(b1[City::London] == 4);

        itay.take_card(City::Miami)
        .take_card(City::MexicoCity)
        .take_card(City::BuenosAires)    // Has 3 Yellows
        .take_card(City::Algiers)        // Has 1 Black
        .take_card(City::Montreal)      // Has 1 Blue
        .take_card(City::Manila);       // Has 1 Red

        CHECK_NOTHROW(itay.discover_cure(Color::Blue));

        CHECK_NOTHROW(noah.treat(City::London));

        CHECK(b1[City::London] == 0);

        noah.take_card(City::StPetersburg);
        CHECK_NOTHROW(noah.fly_direct(City::StPetersburg));


        b1[City::Essen] = 6;
        b1[City::Moscow] = 3;
        b1[City::Istanbul] = 2;

        simha.take_card(City::Moscow)
        .take_card(City::Istanbul);


        CHECK_NOTHROW(noah.treat(City::Moscow));

        CHECK_EQ(b1[City::Moscow],2);

        CHECK_NOTHROW(simha.treat(City::Moscow));

        CHECK_EQ(b1[City::Moscow],1);

        CHECK_NOTHROW(noah.treat(City::Essen));
        CHECK_NOTHROW(noah.treat(City::Moscow));

        CHECK_EQ(b1[City::Moscow],0);
        CHECK_EQ(b1[City::Essen],0);


        CHECK(b1.is_clean() == false);

        CHECK_THROWS(simha.treat(City::Moscow)); // ZERO

        CHECK_NOTHROW(simha.treat(City::Istanbul));
        CHECK_EQ(b1[City::Istanbul],1);
        CHECK_NOTHROW(simha.treat(City::Istanbul));    

        CHECK(b1.is_clean() == true);   
        


    }  

         



}