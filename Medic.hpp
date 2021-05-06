#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class Medic: public Player{
    public:
        Medic(Board game, City town):Player(game, town){} 
        Medic& treat(City);
        Medic& drive(City);
        Medic& fly_direct(City);
        Medic& fly_shuttle(City);
        Medic& fly_charter(City);
        const std::string role() const{
            return "Medic";
        }
    };
}