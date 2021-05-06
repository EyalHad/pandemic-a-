#include "Scientist.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Scientist& Scientist::discover_cure(Color color){
    if (game.getCure(color)){return *this;}
    else if(!game.getResearchS(this->town)) 
        {throw invalid_argument ("Need to Build Research Station FIRST !, Cannot dicover_cure()");}
    int i = 0;
    for(auto& card : cards){
        City town = card.first;
        Color townColor = game.getTown(town).color;
        if (cards[town] && townColor == color)            {
            i++;
        }
        if (i == get()){ break; }
    }
    if (i != get()) {throw invalid_argument ("Need 5 Cards with Same Color !, Cannot dicover_cure()");}
        
    for(auto& card : cards){
        City town = card.first;
        Color townColor = game.getTown(town).color;
        if (cards[town] && townColor == color)
        {
            cards[town] = false;
            i--;
        }
        if (i == 0){ break; }
    }
    return *this;
}