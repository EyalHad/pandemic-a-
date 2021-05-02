#include "FieldDoctor.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


using namespace std;
using namespace pandemic;

FieldDoctor& FieldDoctor::treat(City){
    return *this;
}