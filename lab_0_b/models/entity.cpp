#include "entity.h"

//definition class
using namespace models;

entity::entity(string str)// constructor
{
    string temp;
    for(int i = 0, j = 0; i <= str.length(); i++)
    {
        if(i != str.length() && str[i] != ' ')
        {
            temp += str[i];
        }
        else 
        {
            switch(j)
            {
                case 0:
                    _word = temp;
                    break;
                case 1:
                    _frequency = stoi(temp);
                    break;
                case 2:
                    _percent = stof(temp);
                    break;
            }
            temp = "";
            j++;
        }
    }
}

int32_t entity::getFrequency() const
{
    return _frequency;
}

string entity::getWord() const
{
    return _word;
}
           
float entity::getPercent() const
{
    return _percent;
}
