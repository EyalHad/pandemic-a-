#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

using namespace std;

namespace pandemic {

    class Player {

        protected:
            Board& game;
            map<const City,bool> cards;
            City town;

        public:
            Player(Board& game, City town): game(game), town(town){remove_cards();}
            Player& take_card(const City&);
            virtual Player& drive(const City&);
            virtual Player& fly_charter(const City&);
            virtual Player& fly_shuttle(const City&);

            Player& remove_cards(){
                for(auto& card : cards){card.second = false;}
                return *this;
            }

            virtual const string role(){ return "Player";}
            virtual Player& fly_direct(const City&);
            virtual Player& build();
            virtual Player& discover_cure(const Color&);
            virtual Player& treat(const City&);

    };

}