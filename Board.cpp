#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;
using namespace pandemic;



// class Node{
//     private:
//         City name;
//         Color color;
//     public:
//         bool Reaserch = false;
//         int diseaseCount = 0;

//     Node(City T,Color C):name(T),color(C){}   
// };
// map<Node,set<Node>> _TownsMap;
// map<City,Node> Towns;

// void initiateGame(map<Node,set<Node>>& _TownsMap){
//     // Algiers = 0, Baghdad, Cairo, Chennai, Delhi, Istanbul = 5, Karachi, Kolkata, Moscow, Mumbai, Riyadh, Tehran = 11,
//     Node Algiers(City::Algiers, Color::Black);
//     Node Baghdad(City::Baghdad, Color::Black);
//     Node Cairo(City::Cairo, Color::Black);
//     Node Chennai(City::Chennai, Color::Black);
//     Node Delhi(City::Delhi, Color::Black);
//     Node Istanbul(City::Istanbul, Color::Black);
//     Node Karachi(City::Karachi, Color::Black);
//     Node Kolkata(City::Kolkata, Color::Black);
//     Node Moscow(City::Moscow, Color::Black);
//     Node Mumbai(City::Mumbai, Color::Black);
//     Node Riyadh(City::Riyadh, Color::Black);
//     Node Tehran(City::Tehran, Color::Black);
//     // Bangkok = 12, Beijing, HoChiMinhCity, HongKong, Jakarta, Manila = 17, Osaka, Seoul, Shanghai, Sydney, Taipei, Tokyo = 23,
//     Node Bangkok(City::Bangkok, Color::Red);
//     Node Beijing(City::Beijing, Color::Red);
//     Node HoChiMinhCity(City::HoChiMinhCity, Color::Red);
//     Node HongKong(City::HongKong, Color::Red);
//     Node Jakarta(City::Jakarta, Color::Red);
//     Node Manila(City::Manila, Color::Red);
//     Node Osaka(City::Osaka, Color::Red);
//     Node Seoul(City::Seoul, Color::Red);
//     Node Shanghai(City::Shanghai, Color::Red);
//     Node Sydney(City::Sydney, Color::Red);
//     Node Taipei(City::Taipei, Color::Red);
//     Node Tokyo(City::Tokyo, Color::Red);
//     // Atlanta = 24, Chicago, Essen, London, Madrid, Milan = 29, Montreal, NewYork, Paris, SanFrancisco, StPetersburg, Washington = 35,
//     Node Atlanta(City::Atlanta, Color::Blue);
//     Node Chicago(City::Chicago, Color::Blue);
//     Node Essen(City::Essen, Color::Blue);
//     Node London(City::London, Color::Blue);
//     Node Madrid(City::Madrid, Color::Blue);
//     Node Milan(City::Milan, Color::Blue);
//     Node Montreal(City::Montreal, Color::Blue);
//     Node NewYork(City::NewYork, Color::Blue);
//     Node Paris(City::Paris, Color::Blue);
//     Node SanFrancisco(City::SanFrancisco, Color::Blue);
//     Node StPetersburg(City::StPetersburg, Color::Blue);
//     Node Washington(City::Washington, Color::Blue);
//     // Bogota = 36, BuenosAires, Johannesburg, Khartoum, Kinshasa, Lagos = 41, Lima, LosAngeles, MexicoCity, Miami, Santiago, SaoPaulo = 47,
//     Node Bogota(City::Bogota, Color::Yellow);
//     Node BuenosAires(City::BuenosAires, Color::Yellow);
//     Node Johannesburg(City::Johannesburg, Color::Yellow);
//     Node Khartoum(City::Khartoum, Color::Yellow);
//     Node Kinshasa(City::Kinshasa, Color::Yellow);
//     Node Lagos(City::Lagos, Color::Yellow);
//     Node Lima(City::Lima, Color::Yellow);
//     Node LosAngeles(City::LosAngeles, Color::Yellow);
//     Node MexicoCity(City::MexicoCity, Color::Yellow);
//     Node Miami(City::Miami, Color::Yellow);
//     Node Santiago(City::Santiago, Color::Yellow);
//     Node SaoPaulo(City::SaoPaulo, Color::Yellow);

//     _TownsMap[Algiers] = {Madrid, Paris, Istanbul, Cairo };
//     _TownsMap[Atlanta] = {Chicago, Miami, Washington };
//     _TownsMap[Baghdad] = {Tehran, Istanbul, Cairo, Riyadh, Karachi };
//     _TownsMap[Beijing] = {Shanghai, Seoul };
//     _TownsMap[Bogota] = {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires };
//     _TownsMap[BuenosAires] = {Bogota, SaoPaulo };
//     _TownsMap[Cairo] = {Algiers, Istanbul, Baghdad, Khartoum, Riyadh };
//     _TownsMap[Chennai] = {Mumbai, Delhi, Kolkata, Bangkok, Jakarta };
//     _TownsMap[Chicago] = {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal };
//     _TownsMap[Delhi] = {Tehran, Karachi, Mumbai, Chennai, Kolkata };
//     _TownsMap[Essen] = {London, Paris, Milan, StPetersburg };
//     _TownsMap[HoChiMinhCity] = {Jakarta, Bangkok, HongKong, Manila };
//     _TownsMap[HongKong] = {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei };
//     _TownsMap[Istanbul] = {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow };
//     _TownsMap[Jakarta] = {Chennai, Bangkok, HoChiMinhCity, Sydney };
//     _TownsMap[Johannesburg] = {Kinshasa, Khartoum };
//     _TownsMap[Karachi] = {Tehran, Baghdad, Riyadh, Mumbai, Delhi };
//     _TownsMap[Khartoum] = {Cairo, Lagos, Kinshasa, Johannesburg };
//     _TownsMap[Kinshasa] = {Lagos, Khartoum, Johannesburg };
//     _TownsMap[Kolkata] = {Delhi, Chennai, Bangkok, HongKong };
//     _TownsMap[Lagos] = {SaoPaulo, Khartoum, Kinshasa };
//     _TownsMap[Lima] = {MexicoCity, Bogota, Santiago };
//     _TownsMap[London] = {NewYork, Madrid, Essen, Paris };
//     _TownsMap[LosAngeles] = {SanFrancisco, Chicago, MexicoCity, Sydney };
//     _TownsMap[Madrid] = {London, NewYork, Paris, SaoPaulo, Algiers };
//     _TownsMap[Manila] = {Taipei, SanFrancisco, HoChiMinhCity, Sydney };
//     _TownsMap[MexicoCity] = {LosAngeles, Chicago, Miami, Lima, Bogota };
//     _TownsMap[Miami] = {Atlanta, MexicoCity, Washington, Bogota };
//     _TownsMap[Milan] = {Essen, Paris, Istanbul };
//     _TownsMap[Montreal] = {Chicago, Washington, NewYork };
//     _TownsMap[Moscow] = {StPetersburg, Istanbul, Tehran };
//     _TownsMap[Mumbai] = {Karachi, Delhi, Chennai };
//     _TownsMap[NewYork] = {Montreal, Washington, London, Madrid };
//     _TownsMap[Osaka] = {Taipei, Tokyo };
//     _TownsMap[Paris] = {Algiers, Essen, Madrid, Milan, London };
//     _TownsMap[Riyadh] = {Baghdad, Cairo, Karachi };
//     _TownsMap[SanFrancisco] = {LosAngeles, Chicago, Tokyo, Manila };
//     _TownsMap[SaoPaulo] = {Lima };
//     _TownsMap[Seoul] = {Beijing, Shanghai, Tokyo };
//     _TownsMap[Shanghai] = {Beijing, HongKong, Taipei, Seoul, Tokyo };
//     _TownsMap[StPetersburg] = {Essen, Istanbul, Moscow };
//     _TownsMap[Sydney] = {Jakarta, Manila, LosAngeles };
//     _TownsMap[Taipei] = {Shanghai, HongKong, Osaka, Manila };
//     _TownsMap[Tehran] = {Baghdad, Moscow, Karachi, Delhi };
//     _TownsMap[Tokyo] = {Seoul, Shanghai, Osaka, SanFrancisco };
//     _TownsMap[Washington] = {Atlanta, NewYork, Montreal, Miami };


//     Towns[City::Algiers] = Algiers;
//     Towns[City::Atlanta] = Atlanta;
//     Towns[City::Baghdad] = Baghdad;
//     Towns[City::Beijing] = Beijing;
//     Towns[City::Bogota] = Bogota;
//     Towns[City::BuenosAires] = BuenosAires;
//     Towns[City::Cairo] = Cairo;
//     Towns[City::Chennai] = Chennai;
//     Towns[City::Chicago] = Chicago;
//     Towns[City::Delhi] = Delhi;
//     Towns[City::Essen] = Essen;
//     Towns[City::HoChiMinhCity] = HoChiMinhCity;
//     Towns[City::HongKong] = HongKong;
//     Towns[City::Istanbul] = Istanbul;
//     Towns[City::Jakarta] = Jakarta;
//     Towns[City::Johannesburg] = Johannesburg;
//     Towns[City::Karachi] = Karachi;
//     Towns[City::Khartoum] = Khartoum;
//     Towns[City::Kinshasa] = Kinshasa;
//     Towns[City::Kolkata] = Kolkata;
//     Towns[City::Lagos] = Lagos;
//     Towns[City::Lima] = Lima;
//     Towns[City::London] = London;
//     Towns[City::LosAngeles] = LosAngeles;
//     Towns[City::Madrid] = Madrid;
//     Towns[City::Manila] = Manila;
//     Towns[City::MexicoCity] = MexicoCity;
//     Towns[City::Miami] = Miami;
//     Towns[City::Milan] = Milan;
//     Towns[City::Montreal] = Montreal;
//     Towns[City::Moscow] = Moscow;
//     Towns[City::Mumbai] = Mumbai;
//     Towns[City::NewYork] = NewYork;
//     Towns[City::Osaka] = Osaka;
//     Towns[City::Paris] = Paris;
//     Towns[City::Riyadh] = Riyadh;
//     Towns[City::SanFrancisco] = SanFrancisco;
//     Towns[City::SaoPaulo] = SaoPaulo;
//     Towns[City::Seoul] = Seoul;
//     Towns[City::Shanghai] = Shanghai;
//     Towns[City::StPetersburg] = StPetersburg;
//     Towns[City::Sydney] = Sydney;
//     Towns[City::Taipei] = Taipei;
//     Towns[City::Tehran] = Tehran;
//     Towns[City::Tokyo] = Tokyo;
//     Towns[City::Washington] = Washington;

// }


namespace pandemic{

    Board::Board(){
        // initiateGame(_TownsMap);
    }

    // void setDiease(Node& town, const int& number){ town.diseaseCount = number; }

    bool Board::is_clean() {

        // for (const auto& node : _TownsMap){
        //     if (node.first.diseaseCount != 0){
        //         return false;
        //     }
            
        // }
        return true;  
    }

    // const int Board::operator[] (const City& town) const{
    //     // cout << "Operator[] C " << endl;
    //     return 5;
    // }

    int& Board::operator[] (const City& town){
        // cout << "Operator[] R " << endl;
        // return Towns[town].diseaseCount;
        int r = 6;
        return diseaseCount;
    }

    ostream& operator<< (ostream& os, const Board& game) {
        os << "Game: d"  << game.diseaseCount << endl;
        return os;
    }
    Board& Board::remove_cures(){
        return *this;
    }
};