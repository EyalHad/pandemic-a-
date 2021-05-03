#include <iostream>
#include "Player.hpp"

using namespace std;


namespace pandemic {


    Player& Player::take_card(const City& town) {
        // cout << "take_card" << endl;
        return *this;
    }

    Player& Player::discover_cure(const Color& color) {
        // cout << "discover_cure" << endl;
        return *this;
    }
    Player& Player::drive(const City& town) {
        // cout << "drive" << endl;
        return *this;
    }

    Player& Player::fly_direct(const City& town) {
        // cout << "fly_direct" << endl;
        return *this;
    }
    Player& Player::fly_charter(const City& town) {
        // cout << "fly_charter" << endl;
        return *this;
    }
    Player& Player::fly_shuttle(const City& town) {
        // cout << "fly_shuttle" << endl;
        return *this;
    }
    Player& Player::build() {
        // cout << "build" << endl;
        return *this;
    }


    Player& Player::treat(const City& town) {
        // cout << "treat with city" << endl;
        return *this;
    }
}; 