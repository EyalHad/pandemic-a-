#include "Medic.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
using namespace pandemic;

Medic& Medic::treat(City town){
    Player::treat(town);
    game[town] = 0;
    return *this;
}
Medic& Medic::fly_charter(City town){
    Player::fly_charter(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::fly_direct(City town){
    Player::fly_direct(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::fly_shuttle(City town){
    Player::fly_shuttle(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}
Medic& Medic::drive(City town){
    Player::drive(town);
    if (game.getCure(game.getTown(town).color)){ game[town] = 0;}
    return *this;
}