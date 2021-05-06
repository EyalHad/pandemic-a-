#include "Researcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Researcher& Researcher::discover_cure(Color color){
    if (game.getCure(color)){return *this;}
    int i = 0;
    for(auto& card : cards){
        City town = card.first;
        Color townColor = game.getTown(town).color;
        if (cards[town] && townColor == color){ i++; }
        if (i == 5){ break; }
    }
    if (i != 5) {throw invalid_argument ("Need 5 Cards with Same Color !, Cannot dicover_cure()");}
    for(auto& card : cards){
        City town = card.first;
        Color townColor = game.getTown(town).color;
        if (cards[town] && townColor == color){
            cards[town] = false;
            i--;
        }
        if (i == 0){ break; }
    }   
    return *this;
}