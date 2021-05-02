#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Dispatcher: public Player{
    public:
        Dispatcher(Board game, City town):Player(game, town){} 
        Dispatcher& fly_direct(City);
        const std::string role() const{
            return "Dispatcher";
        }
    };
}