#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Researcher: public Player{
    public:
        Researcher(Board game, City town):Player(game, town){} 
        Researcher& discover_cure(Color);
        const std::string role() const{
            return "Researcher";
        }
    };
}