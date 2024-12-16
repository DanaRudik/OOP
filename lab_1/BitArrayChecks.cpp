// BitArrayChecks.cpp
#include "BitArray.h"

// Проверки

// Есть ли единицы?
bool BitArray::any() const
{
    for (int i = 0; i < byte; i++)
    {
        if (array[i] != 0)
        {
            return true;
        }
    }
    return false;
}

// Нет единиц?
bool BitArray::none() const
{
    return !any(); // Используем уже реализованный метод
}

int BitArray::count() const {
    int count = 0;
    for (int i = 0; i < bits; i++) {
        int idByte = byte - (i / 8) - 1; // Определяем индекс байта
        if (idByte >= 0 && (array[idByte] & (1UL << (i % 8)))) {
            count++;
        }
    }
    return count;
}



// Количество единиц
// int BitArray::count() const {
//     int count = 0;
//     for (int i = 0; i < bits; i++) {
//         int idByte = byte - (i / 8);
//         if (array[byte - 1] & (1UL << i)) {
//             count++;
//         }
//     }
//     return count;
// }

// Значение по индексу
bool BitArray::operator[](int i) const
{
    return (array[i / 8] & (1 << (7 - i % 8))) != 0; // Упрощение
}

// Размер
int BitArray::size() const { return byte; }

// Пустая ли структура
bool BitArray::empty() const { return bits == 0; }// Проверка на ноль битов


// Печать массива
std::string BitArray::to_string() const {
        std::string arr;
        arr.reserve(bits); //резервируем место для массива
        for (int i = 0; i < bits; i++) {
            arr += (array[i / 8] & (1 << (7 - i % 8))) ? '1' : '0';
        }
        return arr;
}