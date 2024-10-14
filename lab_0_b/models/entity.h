#pragma once

#include<string>
#include<stdint.h>
#include<fstream>

//decloration class
using namespace std;

namespace models
{   
    class entity
    {
        public:
           entity(string str); // constructor
           int32_t getFrequency() const;
           string getWord() const;
           float getPercent() const;

           friend ofstream& operator<<(ofstream& os, const entity& c)
           {
                string a = ";";
                os << c.getWord() 
                << a 
                << to_string(c.getFrequency()) 
                << a 
                << to_string(c.getPercent())
                << endl; 
                return os; 
           }

        private:
            string _word;
            int32_t _frequency;
            float _percent;
    };
}