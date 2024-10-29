#include "entity.h"

//definition class
using namespace models;

entity::entity(string word, int32_t frequency, float percent)// constructor
: _frequency(frequency), _word(word), _percent(percent)
{

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
