#pragma once
#include<string>
#include<stdint.h>

//decloration class
using namespace std;

namespace models
{   
    class entity
    {
        public:
           entity(string str); // constructor

        private:
            string _word;
            int32_t _frequency;
            int32_t _percent;
    };
}