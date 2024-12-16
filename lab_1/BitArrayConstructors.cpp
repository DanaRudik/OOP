// BitArray.cpp
#include "BitArray.h"
#include <bitset>
              
BitArray::BitArray() : bits(0), byte(0), array(nullptr){}// Конструктор по умолчанию

BitArray::~BitArray() // Деструктор
{ 
    delete[] array; 
}

BitArray::BitArray(int num_bits, unsigned long value) {// Явный конструктор
    bits = num_bits;
    byte = (num_bits + 7) / 8; // определение количества байт

    array = new unsigned char[byte]; 
    for (int i = 0; i < byte; i++) {
        array[i] = 0; 
    }

    for (int i = 0; i < num_bits; i++) {// Заполняем массив битами из заданного значения
        if (value & (1UL << i)) { // проверяем установлен ли i-й бит в value
            int idByte =  byte - (i / 8);
            array[idByte - 1] |= (1UL << i); // устанавливаем бит в соответствующем байте
        }
    }
}

BitArray::BitArray(const BitArray& b)// Конструктор копирования
  : bits(b.bits), byte(b.byte)
{
    array = new unsigned char[byte];
    std::copy(b.array, b.array + byte, array);
}
