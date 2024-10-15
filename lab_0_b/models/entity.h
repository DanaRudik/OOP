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
                os << c._word
                << a 
                << to_string(c._frequency) 
                << a 
                << to_string(c._percent)
                << endl; 
                return os; 
           }

        private:
            string _word;
            int32_t _frequency;
            float _percent;
    };
}