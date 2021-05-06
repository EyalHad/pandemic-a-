#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City town){
    if(game.getTown(this->town).reachable.find(town) == game.getTown(this->town).reachable.end()){
        throw invalid_argument("Do not in requested/Neighbor City, City Current: "+Sity::toString(this->town)
        +"Tried to: "+Sity::toString(town)+" Cannot use treat()");
    }
    else if (game.getCure(game.getTown(town).color)){
        game[town] = 0;
    }else{ game[town]--;}
    
    return *this;
}