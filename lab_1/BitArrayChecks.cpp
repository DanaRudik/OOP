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

// Значение по индексу
bool BitArray::operator[](int i) const
{
    return (array[i / 8] & (1 << (7 - i % 8))) != 0; // Упрощение
}

// Размер
int BitArray::size() const { return bits; }

// Пустая ли структура
bool BitArray::empty() const { return bits == 0; }// Проверка на ноль битов


// Массив как строка
std::string& BitArray::to_string() const {
        std::string& arr = *(new std::string());
        int a = bits - 1;
        int BitsCount = 7-(a % 8); //вычисляем индекс в байтовом массиве для нашего битового массива
        for (int i = 0; i < bits; i++) {
            int idBits = a % 8;
            int idByte = BitsCount / 8;
            arr += (array[idByte] & (1 << idBits)) ? '1' : '0';
            a--;
            BitsCount++;
        }
        return arr;
}