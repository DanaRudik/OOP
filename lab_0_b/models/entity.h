#pragma once
#include<string>
#include<stdint.h>

using namespace std;

namespace models
{   
    class entity
    {
        public:

        private:
            string _word;
            int32_t _frequency;
            int32_t _percent;
    };
}