#include "BitArray.h"

#define MAX 255

// Установка бита по индексу n в значение val
BitArray& BitArray::set(int n, bool val)
{
    int pos = n / 8;
    int step = 7 - n % 8;

    if (val)
    {
        array[pos] |= (1 << step);
    }
    else
    {
        array[pos] &= ~(1 << step);
    }
    return *this;
}

// Заполнение массива единицами
BitArray& BitArray::set()
{        
    std::fill(array, array + byte, MAX); // Используем стандартную библиотеку для заполнения
    return *this;
}

// Сброс бита по индексу n в false
BitArray& BitArray::reset(int n)
{
    int pos = n / 8;
    int step = 7 - n % 8;

    array[pos] &= ~(1 << step);
    return *this;
}

// Заполнение массива нулями
BitArray& BitArray::reset()
{
    std::fill(array, array + byte, 0); // Используем стандартную библиотеку
    return *this;
}