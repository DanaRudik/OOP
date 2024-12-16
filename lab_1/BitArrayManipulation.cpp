// BitArrayManipulation.cpp
#include "BitArray.h"

// Изменение размера
void BitArray::resize(int num_bits, bool value)                             
{
    int new_byte = (num_bits + 7) / 8; // округление вверх

    if (bits == num_bits)
        return;       

    unsigned char* new_array = new unsigned char[new_byte](); // выделение и инициализация

    // Копирование старых данных
    std::copy(array, array + std::min(byte, new_byte), new_array);
    
    // Очистка лишних битов, если новый размер меньше
    if (num_bits < bits)
    {
        int clear_bits = (8 - (num_bits % 8)) % 8;
        for (int i = 0; i < clear_bits; i++) {
            new_array[new_byte - 1] &= ~(1 << i);
        }
    }

    delete[] array; // Удаляем старый массив
    array = new_array; // Устанавливаем новый массив

    bits = num_bits;
    byte = new_byte;
}

// Очистка
void BitArray::clear()
{
    delete[] array;
    array = nullptr;
    bits = 0;
    byte = 0;
}

// Добавить один бит
void BitArray::push_back(bool bit)
{
    resize(bits + 1, false);
    
    int bit_index = bits % 8;
    if (bit)
    {
        array[byte - 1] |= (1 << bit_index);
    }
    else
    {
        array[byte - 1] &= ~(1 << bit_index);
    }
}

// Другие методы                                           

// Обмен
void BitArray::swap(BitArray& b)
{
    if (bits != b.bits)
    {
        throw std::invalid_argument("The sizes are not the same.\n");
    }
    
    std::swap(array, b.array);
}
