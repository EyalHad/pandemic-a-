#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

using namespace std;

namespace pandemic {

    class Player {

        protected:
            Board& game;
            set<City> cards;
            City town;

        public:
            Player(Board& game, City town): game(game), town(town){}
            Player& take_card(const City&);
            Player& drive(const City&);
            Player& fly_charter(const City&);
            Player& fly_shuttle(const City&);

            virtual const string role(){ return "Player";}
            virtual Player& fly_direct(const City&);
            virtual Player& build();
            virtual Player& discover_cure(const Color&);
            virtual Player& treat();
            virtual Player& treat(const City&);

    };

}