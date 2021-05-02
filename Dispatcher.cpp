#include "Dispatcher.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

Dispatcher& Dispatcher::fly_direct(City){
    return *this;
}