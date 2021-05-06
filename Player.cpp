#include <iostream>
#include "Player.hpp"
#include <set>
using namespace std;


namespace pandemic {


    Player& Player::take_card(const City& town) {
        cards[town] = true;
        return *this;
    }

    Player& Player::discover_cure(const Color& color) {
        if (game.getCure(color)){return *this;}
        else if(!game.getResearchS(this->town)) 
            {throw invalid_argument ("Need to Build Research Station FIRST !, Cannot dicover_cure()");}
        int i = 0;
        for(auto& card : cards){
            City town = card.first;
            Color townColor = game.getTown(town).color;
            if (cards[town] && townColor == color)
            {
                i++;
            }
            if (i == 5){ break; }
        }
        if (i != 5) {throw invalid_argument ("Need 5 Cards with Same Color !, Cannot dicover_cure()");}
        
        for(auto& card : cards){
            City town = card.first;
            Color townColor = game.getTown(town).color;
            if (cards[town] && townColor == color)
            {
                cards[town] = false;
                i--;
            }
            if (i == 0){ break; }
        }
        return *this;
    }
    Player& Player::drive(const City& town) {
        if (this->town == town){throw invalid_argument("Cannot Drive there !, We Are Already Here"); }
        else if (game.getTown(this->town).reachable.find(town) != game.getTown(this->town).reachable.end()){
            this->town = town;
        }else { throw invalid_argument("Cannot Drive there !, Not a Neighbor City");}
        return *this;
    }

    Player& Player::fly_direct(const City& town) {
        if (cards[town]){
            this->town = town;
        }else { throw invalid_argument("We Do not have the Card: " + Sity::toString(town) + " Cannot use fly_direct()");}
        return *this;
    }
    Player& Player::fly_charter(const City& town) {
        if (cards[this->town]){
            this->town = town;
        }else{ throw invalid_argument("We Do not have the Card: " + Sity::toString(this->town)+ " Cannot use fly_charter()");}
        
        return *this;
    }
    Player& Player::fly_shuttle(const City& town) {
        if (game.getResearchS(this->town)){
            if (game.getResearchS(town)){
                this->town = town;
            }else{ throw invalid_argument("No Research Station in: " + Sity::toString(town) + " Cannot use fly_shuttle()");}  
        }else{ throw invalid_argument("No Research Station in: " + Sity::toString(this->town)+ " Cannot use fly_shuttle()");}
        
        return *this;
    }
    Player& Player::build() {
        if (game.getResearchS(this->town)){ return *this; }
        else{
            if (cards[this->town]){
                game.getTown(this->town).Reaserch = true;
            }else{ throw invalid_argument("We Do not have the Card: " + Sity::toString(town) + " Cannot use build()");}
        }
        return *this;
    }


    Player& Player::treat(const City& town) {
        if (this->town != town){ throw invalid_argument("Do not in requested, City Current: "+Sity::toString(this->town)
        +"Tried to: "+Sity::toString(town)+" Cannot use treat()");}
        else if (game[town] <= 0){
            throw invalid_argument("Diease level is ZERO Cannot use treat()");
        }else if(game.getCure(game.getTown(town).color)){ game[town] = 0; }
        else{ game[town]--;}
        return *this;
    }
}; 