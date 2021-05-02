#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class Medic: public Player{
    public:
        Medic(Board game, City town):Player(game, town){} 
        Medic& treat();
        const std::string role() const{
            return "Medic";
        }
    };
}