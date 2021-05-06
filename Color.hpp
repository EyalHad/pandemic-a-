#pragma once
#include <string>


	enum Color {

        Black = 0,
        Red = 12,
        Blue = 24,
        Yellow = 36,
        
	};

namespace Sity {

        inline std::string toString(Color color){
            switch (color){
                case Black : return "Black"; break;
                case Blue : return "Blue"; break;
                case Red : return "Red"; break;
                case Yellow : return "Yellow"; break;

            }            
        }

        inline Color toColor(std::string txt){
                if(txt == "Black") return Color::Black;
                else if(txt == "Red") return Color::Red;
                else if(txt == "Blue") return Color::Blue;
                else return Color::Yellow;
        }
}