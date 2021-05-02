#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class OperationsExpert: public Player{
    public:
        OperationsExpert(Board game, City town):Player(game, town){} 
        OperationsExpert& build();
        const std::string role() const{
            return "OperationsExpert";
        }
    };
}