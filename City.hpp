#pragma once
#include <string>



	enum City {

		/**	BLACK */
        Algiers = 0, Baghdad, Cairo, Chennai, Delhi, Istanbul = 5, Karachi, Kolkata, Moscow, Mumbai, Riyadh, Tehran = 11,

        /**	RED */
        Bangkok = 12, Beijing, HoChiMinhCity, HongKong, Jakarta, Manila = 17, Osaka, Seoul, Shanghai, Sydney, Taipei, Tokyo = 23,

        /** BLUE */
        Atlanta = 24, Chicago, Essen, London, Madrid, Milan = 29, Montreal, NewYork, Paris, SanFrancisco, StPetersburg, Washington = 35,

        /** YELLOW */ 
        Bogota = 36, BuenosAires, Johannesburg, Khartoum, Kinshasa, Lagos = 41, Lima, LosAngeles, MexicoCity, Miami, Santiago, SaoPaulo = 47,

         
	};
namespace Sity{

    inline std::string toString(City city){

        // The Idea is from Stackoverflow -> I wish there was something better
        switch (city){
        case Algiers : return "Algiers"; break; 
        case Atlanta : return "Atlanta"; break; 
        case Baghdad : return "Baghdad"; break; 
        case Bangkok : return "Bangkok"; break; 
        case Beijing : return "Beijing"; break; 
        case Bogota : return "Bogota"; break; 
        case BuenosAires : return "BuenosAires"; break; 
        case Cairo : return "Cairo"; break; 
        case Chennai : return "Chennai"; break; 
        case Chicago : return "Chicago"; break; 
        case Delhi : return "Delhi"; break; 
        case Essen : return "Essen"; break; 
        case HoChiMinhCity : return "HoChiMinhCity"; break; 
        case HongKong : return "HongKong"; break; 
        case Istanbul : return "Istanbul"; break; 
        case Jakarta : return "Jakarta"; break; 
        case Johannesburg : return "Johannesburg"; break; 
        case Karachi : return "Karachi"; break; 
        case Khartoum : return "Khartoum"; break; 
        case Kinshasa : return "Kinshasa"; break; 
        case Kolkata : return "Kolkata"; break; 
        case Lagos : return "Lagos"; break; 
        case Lima : return "Lima"; break; 
        case London : return "London"; break; 
        case LosAngeles : return "LosAngeles"; break; 
        case Madrid : return "Madrid"; break; 
        case Manila : return "Manila"; break; 
        case MexicoCity : return "MexicoCity"; break; 
        case Miami : return "Miami"; break; 
        case Milan : return "Milan"; break; 
        case Montreal : return "Montreal"; break; 
        case Moscow : return "Moscow"; break; 
        case Mumbai : return "Mumbai"; break; 
        case NewYork : return "NewYork"; break; 
        case Osaka : return "Osaka"; break; 
        case Paris : return "Paris"; break; 
        case Riyadh : return "Riyadh"; break; 
        case SanFrancisco : return "SanFrancisco"; break; 
        case Santiago : return "Santiago"; break; 
        case SaoPaulo : return "SaoPaulo"; break; 
        case Seoul : return "Seoul"; break; 
        case Shanghai : return "Shanghai"; break; 
        case StPetersburg : return "StPetersburg"; break; 
        case Sydney : return "Sydney"; break; 
        case Taipei : return "Taipei"; break; 
        case Tehran : return "Tehran"; break; 
        case Tokyo : return "Tokyo"; break; 
        case Washington : return "Washington"; break; 
        }
    }


    inline City toCity(std::string city){

            if(city == "Algiers") return City::Algiers;
            else if(city == "Atlanta") return City::Atlanta;
            else if(city == "Baghdad") return City::Baghdad;
            else if(city == "Bangkok") return City::Bangkok;
            else if(city == "Beijing") return City::Beijing;
            else if(city == "Bogota") return City::Bogota;
            else if(city == "BuenosAires") return City::BuenosAires;
            else if(city == "Cairo") return City::Cairo;
            else if(city == "Chennai") return City::Chennai;
            else if(city == "Chicago") return City::Chicago;
            else if(city == "Delhi") return City::Delhi;
            else if(city == "Essen") return City::Essen;
            else if(city == "HoChiMinhCity") return City::HoChiMinhCity;
            else if(city == "HongKong") return City::HongKong;
            else if(city == "Istanbul") return City::Istanbul;
            else if(city == "Jakarta") return City::Jakarta;
            else if(city == "Johannesburg") return City::Johannesburg;
            else if(city == "Karachi") return City::Karachi;
            else if(city == "Khartoum") return City::Khartoum;
            else if(city == "Kinshasa") return City::Kinshasa;
            else if(city == "Kolkata") return City::Kolkata;
            else if(city == "Lagos") return City::Lagos;
            else if(city == "Lima") return City::Lima;
            else if(city == "London") return City::London;
            else if(city == "LosAngeles") return City::LosAngeles;
            else if(city == "Madrid") return City::Madrid;
            else if(city == "Manila") return City::Manila;
            else if(city == "MexicoCity") return City::MexicoCity;
            else if(city == "Miami") return City::Miami;
            else if(city == "Milan") return City::Milan;
            else if(city == "Montreal") return City::Montreal;
            else if(city == "Moscow") return City::Moscow;
            else if(city == "Mumbai") return City::Mumbai;
            else if(city == "NewYork") return City::NewYork;
            else if(city == "Osaka") return City::Osaka;
            else if(city == "Paris") return City::Paris;
            else if(city == "Riyadh") return City::Riyadh;
            else if(city == "SanFrancisco") return City::SanFrancisco;
            else if(city == "Santiago") return City::Santiago;
            else if(city == "SaoPaulo") return City::SaoPaulo;
            else if(city == "Seoul") return City::Seoul;
            else if(city == "Shanghai") return City::Shanghai;
            else if(city == "StPetersburg") return City::StPetersburg;
            else if(city == "Sydney") return City::Sydney;
            else if(city == "Taipei") return City::Taipei;
            else if(city == "Tehran") return City::Tehran;
            else if(city == "Tokyo") return City::Tokyo;
            else return City::Washington;

    }
}


/**
Algiers Black Madrid Paris Istanbul Cairo
Atlanta Blue Chicago Miami Washington
Baghdad Black Tehran Istanbul Cairo Riyadh Karachi
Bangkok Red Kolkata Chennai Jakarta HoChiMinhCity HongKong
Beijing Red Shanghai Seoul
Bogota Yellow MexicoCity Lima Miami SaoPaulo BuenosAires
BuenosAires Yellow Bogota SaoPaulo
Cairo Black Algiers Istanbul Baghdad Khartoum Riyadh
Chennai Black Mumbai Delhi Kolkata Bangkok Jakarta
Chicago Blue SanFrancisco LosAngeles MexicoCity Atlanta Montreal
Delhi Black Tehran Karachi Mumbai Chennai Kolkata
Essen Blue London Paris Milan StPetersburg
HoChiMinhCity Red Jakarta Bangkok HongKong Manila
HongKong Red Bangkok Kolkata HoChiMinhCity Shanghai Manila Taipei
Istanbul Black Milan Algiers StPetersburg Cairo Baghdad Moscow
Jakarta Red Chennai Bangkok HoChiMinhCity Sydney
Johannesburg Yellow Kinshasa Khartoum
Karachi Black Tehran Baghdad Riyadh Mumbai Delhi
Khartoum Yellow Cairo Lagos Kinshasa Johannesburg
Kinshasa Yellow Lagos Khartoum Johannesburg
Kolkata Black Delhi Chennai Bangkok HongKong
Lagos Yellow SaoPaulo Khartoum Kinshasa
Lima Yellow MexicoCity Bogota Santiago
London Blue NewYork Madrid Essen Paris
LosAngeles Yellow SanFrancisco Chicago MexicoCity Sydney
Madrid Blue London NewYork Paris SaoPaulo Algiers
Manila Red Taipei SanFrancisco HoChiMinhCity Sydney
MexicoCity Yellow LosAngeles Chicago Miami Lima Bogota
Miami Yellow Atlanta MexicoCity Washington Bogota
Milan Blue Essen Paris Istanbul
Montreal Blue Chicago Washington NewYork
Moscow Black StPetersburg Istanbul Tehran
Mumbai Black Karachi Delhi Chennai
NewYork Blue Montreal Washington London Madrid
Osaka Red Taipei Tokyo
Paris Blue Algiers Essen Madrid Milan London
Riyadh Black Baghdad Cairo Karachi
SanFrancisco Blue LosAngeles Chicago Tokyo Manila
Santiago Yellow Lima
SaoPaulo Yellow Bogota BuenosAires Lagos Madrid
Seoul Red Beijing Shanghai Tokyo
Shanghai Red Beijing HongKong Taipei Seoul Tokyo
StPetersburg Blue Essen Istanbul Moscow
Sydney Red Jakarta Manila LosAngeles
Taipei Red Shanghai HongKong Osaka Manila
Tehran Black Baghdad Moscow Karachi Delhi
Tokyo Red Seoul Shanghai Osaka SanFrancisco
Washington Blue Atlanta NewYork Montreal Miami
*/