#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
using namespace Sity;

#include <iostream>

#include <map>
#include <set>

#include <fstream>

using namespace std;
using namespace pandemic;



namespace pandemic{

    Board::Board(){
        ifstream file{"cities_map.txt"};

        string line;
        string town;

        while (getline(file,line))
        {
            Node city;
            int i = 0;
            string dummy;
            unsigned long pos = 0;
            while (pos != string::npos)
            {
                pos = line.find(" ");
                dummy = line.substr(0,pos);
                if (i == 0)
                {
                    town = dummy;
                    _TownsMap[Sity::toCity(town)];
                }else if (i ==1){
                    _TownsMap[Sity::toCity(town)].color = Sity::toColor(dummy);
                }else{
                    _TownsMap[Sity::toCity(town)].reachable.insert(Sity::toCity(dummy));
                }
                line.erase(0,pos+1);
                i++;   
            }
            dummy = line;
            _TownsMap[Sity::toCity(town)].reachable.insert(Sity::toCity(dummy));
            
            
            
        }
           
    }

    int& Board::operator[] (const City& town){
        if (_TownsMap.find(town) != _TownsMap.end()){
        return _TownsMap[town].diseaseCount;}
        else{ throw invalid_argument("This: "+Sity::toString(town)+" Outside The Game Map :(");}
    }


    ostream& operator<< (ostream& os, const Board& game) {
        for (auto& Town: game._TownsMap)
        {   
            os <<  "[";
            switch (Town.second.color)
            {
            case Color::Blue:
                os << "\x1B[36m Blue \033[0m";
                break;
            case Color::Red:
                os << "\x1B[31m Red \033[0m";
                break;
            case Color::Yellow:
                os << "\x1B[93m Yellow \033[0m";
                break;
            
            default:
                os << "\x1B[1;20;30m Black \033[0m";
                break;
            }
            os << "] "<< "Name: [" << Sity::toString( Town.first) << "] <->" << "\t{ ";
            int i = 0;
            for(const City& Neighbor : Town.second.reachable){
                os << "(" << i << ") " << Sity::toString(Neighbor) << ", ";
                i++;
            }
            os << "}\n";
        }
        
        return os;
    }

};