#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;




namespace pandemic {

    class Board
    {

        
    public:
        int diseaseCount;
        Board();

        //_________________________________
        int& get(){ return diseaseCount;}
        //_________________________________
        bool is_clean();
        // const int operator[] (const City&) const;
        int& operator[] (const City&) ;
        friend ostream& operator<< (std::ostream&, const Board& game);
    };



}