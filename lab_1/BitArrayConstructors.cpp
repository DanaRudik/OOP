// BitArray.cpp
#include "BitArray.h"
#include <bitset>
// Конструкторы и Деструктор                   

// Конструктор по умолчанию
BitArray::BitArray() : bits(0), byte(0), array(nullptr){}

// Деструктор
BitArray::~BitArray() 
{ 
    delete[] array; 
}

// Явный конструктор
BitArray::BitArray(int num_bits, unsigned long value) {
    bits = num_bits;
    byte = (num_bits + 7) / 8; // округление вверх для определения количества байт

    array = new unsigned char[byte]; // выделяем память под массив
    for (int i = 0; i < byte; i++) {
        array[i] = 0; // инициализируем массив нулями
    }

    // Заполняем массив битами из заданного значения
    for (int i = 0; i < num_bits; i++) {
        if (value & (1UL << i)) { // проверяем установлен ли i-й бит в value
            int idByte =  byte - (i / 8);
            array[idByte - 1] |= (1UL << i); // устанавливаем бит в соответствующем байте
        }
    }
}

// Конструктор копирования
BitArray::BitArray(const BitArray& b)
  : bits(b.bits), byte(b.byte)
{
    array = new unsigned char[byte];
    std::copy(b.array, b.array + byte, array);
}
