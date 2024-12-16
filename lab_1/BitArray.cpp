#include <iostream>
#include "BitArray.h"
#include <cmath>

// Операторы двух массивов

// Равенство
bool operator==(const BitArray& a, const BitArray& b)
{
    if (a.size() != b.size())
    {
        return false;
    }

    for (int i = 0; i < a.size() / 8; i++)
    {
        if (a.getElement(i) != b.getElement(i))
        {
            return false;
        }
    }

    return true;
}

// Неравенство
bool operator!=(const BitArray& a, const BitArray& b)
{
    return !(a == b); // Используем перегруженный оператор равенства
}

// Логическое "AND"
BitArray operator&(const BitArray& b1, const BitArray& b2)
{
    if (b1.size() != b2.size())
    {
        throw std::invalid_argument("The arrays' sizes are not the same.\n");
    }
    
    BitArray result = b1;
    result &= b2; // Используем перегруженный оператор

    return result;
}

// Логическое "OR"
BitArray operator|(const BitArray& b1, const BitArray& b2)
{
    if (b1.size() != b2.size())
    {
        throw std::invalid_argument("The arrays' sizes are not the same.\n");
    }
    
    BitArray result = b1;
    result |= b2; // Используем перегруженный оператор

    return result;
}

// "XOR"
BitArray operator^(const BitArray& b1, const BitArray& b2)
{
    if (b1.size() != b2.size())
    {
        throw std::invalid_argument("The arrays' sizes are not the same.\n");
    }
    
    BitArray result = b1;
    result ^= b2; // Используем перегруженный оператор

    return result;
}
