// BitArrayManipulation.cpp
#include "BitArray.h"

// Изменение размера
void BitArray::resize(int num_bits, bool value)                             
{
    if (bits == num_bits) return;   

    int new_byte = (num_bits + 7) / 8; 
    unsigned char* new_array = new unsigned char[new_byte](); // выделение и инициализация

    std::copy(array, array + std::min(byte, new_byte), new_array);// Копирование старых данных
    
    if (num_bits < bits)    // Очистка лишних битов, если новый размер меньше
    {
        int clear_bits = (byte*8) - num_bits;
        for (int i = 0; i < clear_bits; i++) {
            int idBits = 7 - (i%8);
            new_array[i/8] &= ~(1 << idBits);
        }
    }

    delete[] array; // Удаляем старый массив
    array = new_array; // Устанавливаем новый массив
    bits = num_bits;
    byte = new_byte;
}

// BitArray& BitArray::operator&=(const BitArray& b)
// {
//     // Проверка на равенство размеров массивов
//     if (bits != b.size) {
//         throw std::invalid_argument("BitArray sizes must be equal.");
//     }

//     // Проходим по каждому биту
//     for (size_t i = 0; i < size * 8; ++i) {
//         // Получаем индекс элемента массива и позицию бита
//         size_t arrayIndex = i / 8;  // Индекс элемента массива
//         size_t bitPosition = i % 8;  // Позиция бита в элементе

//         // Применяем побитовую операцию AND с учетом выбранного бита
//         if ((b.data[arrayIndex] & (1 << bitPosition)) == 0) {
//             this->data[arrayIndex] &= ~(1 << bitPosition);  // Установить в 0
//         }
//         // Если бит равен 1, ничего делать не нужно, он останется 1 или 0 в текущем состоянии
//     }

//     return *this;  // Возвращаем ссылку на текущий объект
// }


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
    
    if (bit){
        array[byte - 1] |= (1 << (bits-1));
    }
    else{
        array[byte - 1] &= ~(1 << (bits-1));
    }
}

// Другие методы                                           

// свопчик
void BitArray::swap(BitArray& b)
{
    if (bits != b.bits)
    {
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (size_t i = 0; i < bits; ++i)
    {
        size_t idByte= i / 8;  // Индекс текущего элемента
        size_t idBit = i % 8;  // Позиция бита в элементе

        // Проверяем, установлен ли бит в этом элементе у обоих массивов
        bool bitA = (array[idByte] & (1 << (idBit))) != 0;
        bool bitB = (b.array[idByte] & (1 << (idBit))) != 0;

        // Обмен значениями битов
        if (bitA != bitB)
        {
            // Меняем состояние битов: если один установлен, устанавливаем другой и наоборот
            array[idByte] ^= (1 << idBit);  // Инвертируем бит в текущем массиве
            b.array[idByte] ^= (1 << idBit); // Инвертируем бит в массиве b
        }
    }
}