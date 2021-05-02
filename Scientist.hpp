#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    class Scientist: public Player{
    private:
        int cards;
    public:
        Scientist(Board game, City town, int cards):Player(game, town),cards(cards){}  
        Scientist& discover_cure(Color);
        const std::string role() const{
            return "Scientist";
        }
    };
}