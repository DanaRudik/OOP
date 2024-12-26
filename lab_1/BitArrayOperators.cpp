#include "BitArray.h"

// and
BitArray& BitArray::operator&=(const BitArray& b)
{
    if (bits != b.bits){
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (int i = 0; i < byte; i++){
        array[i] &= b.array[i];
    }
    return *this;
}

// or
BitArray& BitArray::operator|=(const BitArray& b)
{
    if (bits != b.bits){
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (int i = 0; i < byte; i++){
        array[i] |= b.array[i];
    }
    return *this;
}

// "xor"
BitArray& BitArray::operator^=(const BitArray& b)
{
    if (bits != b.bits){
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (int i = 0; i < byte; i++){
        array[i] ^= b.array[i];
    }
    return *this;
}

// Инверсия
BitArray BitArray::operator~() const
{
    BitArray result(*this); // Создаем копию
    for (int i = 0; i < byte; i++){
        result.array[i] = ~array[i];
    }
    return result;
}

// сдвиг влево
BitArray& BitArray::operator<<(int n)
{
    if (n <= 0) return *this;  // Если n меньше или равно 0, ничего не делаем
    if (n >= (bits * 8)) 
    {
        std::fill(array, array + bits, 0);// Если сдвиг больше или равен общему количеству битов, обнуляем массив
        return *this;
    }

    unsigned char* newArray = new unsigned char[byte](); //выделение и инициализация
    
    int startIndex = (byte * 8)-1; //дефолтный последний индекс в битовом массиве
    int count = startIndex;
    int count_n = n;
    int num_iteration = (byte * 8) - n;

    for (int i = 0; i < num_iteration; i++){ //i отвечает за сдвиги

        int idBits = i % 8;
        int idByte = count / 8;
        int idByteForIndex = startIndex - i;

        if((*this)[idByteForIndex]){ //массивы и оператор индексации не могут быть применены к указателям или экземплярам созданных классов таким образом
            newArray[idByte] |= (1 << count_n);
        }
        
        count_n++; //сдвиг в новом массиве
        count--; //индекс того бита который мы проверяем
    }

    array = newArray;// Устанавливаем новый массив
    return *this;
}

// сдвиг вправо 
BitArray& BitArray::operator>>(int n) 
{
    if (n <= 0) return *this;  // Если n меньше или равно 0, ничего не делаем
    if (n >= (bits * 8)) 
    {
        std::fill(array, array + bits, 0);// Если сдвиг больше или равен общему количеству битов, обнуляем массив
        return *this;
    }

    unsigned char* newArray = new unsigned char[byte](); //выделение и инициализация
    
    int num_iteration = (byte * 8) - n;
    int startIndex = (byte * 8)-1; //дефолтный последний индекс в битовом массиве

    for (int i = 0; i < num_iteration; i++){ //i отвечает за сдвиги
        int idByte = i / 8;
        int idBits = i % 8;

        if((*this)[i]){ //массивы и оператор индексации не могут быть применены к указателям или экземплярам созданных классов таким образом
            newArray[idByte] |= (1 << (startIndex - n));
        }
        n++; //сдвиг в новом массиве
    }

    array = newArray;// Устанавливаем новый массив
    return *this;
}