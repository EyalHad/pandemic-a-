
#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

GeneSplicer& GeneSplicer::discover_cure(Color c){
    int i = 0;
    for(auto& card : cards){ 
        if (cards[card.first]){i++;}
        else if( i == 5) { break; }
    }
    for(auto& card : cards){ 
        if (cards[card.first]){
            cards[card.first] = false;
            i--;
        }
        else if( i == 0) { break; }
    }
    return *this;
}