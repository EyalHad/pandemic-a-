#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class Virologist: public Player{
    public:
        Virologist(Board game, City town): Player(game, town){}
        Virologist& treat(City);
        const std::string role() const{return "Virologist";}
    };
}