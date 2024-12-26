#include "BitArray.h"

// Изменение размера
void BitArray::resize(int num_bits, bool value)                             
{
    if (bits == num_bits) return;   

    int new_byte = (num_bits + 7) / 8; //вычисляем сколько байт нужно на новый массив
    unsigned char* new_array = new unsigned char[new_byte](); // выделение и инициализация

    std::copy(array, array + byte, new_array);// Отрезок(начало, конец), указатель на начало копирования
    
    if (num_bits < bits)    // Очистка лишних битов, если новый размер меньше
    {
        int clear_bits = bits - num_bits; //количество битов, которые нам нужно очистить
        int startClean = (8*new_byte) - bits; //бит для начала очистки, индекс бита в правильном порядке массива

        for (int i = 0; i < clear_bits - 1; i++) {
            int idBits = (7 - startClean) - (i%8); //насколько бит мы сдвинем 1
            new_array[startClean/8] &= ~(1 << idBits);
            startClean++;
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
    this->operator<<(1); //чтобы не вызывать конструктор копирования, мы работаем напрямую с памятью которую выделяли в <<
    std::string& str = (*this).to_string();
    if (bit)
        array[byte - 1] |= (1 << 0);
    bits = bits + 1;
    str = (*this).to_string();
}

// свопчик
void BitArray::swap(BitArray& b)
{
    if (bits != b.bits){
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (int i = 0; i < bits; ++i)
    {
        int idByte= i / 8;  // Индекс текущего элемента
        int idBit = i % 8;  // Позиция бита в элементе

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