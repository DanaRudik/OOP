// BitArrayOperators.cpp
#include "BitArray.h"

// Логические операторы

// Логическое "AND"
BitArray& BitArray::operator&=(const BitArray& b)
{
    if (bits != b.bits)
    {
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (int i = 0; i < byte; i++)
    {
        array[i] &= b.array[i];
    }

    return *this;
}
/////////////////////////////////////////////////////////////////////////////////
// Логическое "OR"
BitArray& BitArray::operator|=(const BitArray& b)
{
    if (bits != b.bits)
    {
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (int i = 0; i < byte; i++)
    {
        array[i] |= b.array[i];
    }

    return *this;
}

// "XOR"
BitArray& BitArray::operator^=(const BitArray& b)
{
    if (bits != b.bits)
    {
        throw std::invalid_argument("The sizes are not the same.\n");
    }

    for (int i = 0; i < byte; i++)
    {
        array[i] ^= b.array[i];
    }

    return *this;
}

// Инверсия
BitArray BitArray::operator~() const
{
    BitArray result(*this); // Создаем копию

    for (int i = 0; i < byte; i++)
    {
        result.array[i] = ~array[i];
    }

    return result;
}

// Операция сдвига влево
BitArray& BitArray::operator<<=(int n)
{
    if (n <= 0) return *this; // Если сдвиг не положительный, не меняем массив

    int newByte = byte;
    for (int i = 0; i < bits; i++)
    {
        if (i % 8 == 0 && i != 0)
        {
            newByte--;
        }

        int pos = (i + n) / 8;
        int step = 7 - (i + n) % 8;

        if (pos < byte && (array[pos] & (1 << (7 - (i % 8)))))
        {
            array[newByte] |= (1 << step);
        }
        else
        {
            array[newByte] &= ~(1 << step);
        }
    }

    return *this;
}

// Операция сдвига вправо
BitArray& BitArray::operator>>=(int n)
{
    if (n <= 0) return *this; // Если сдвиг не положительный, не меняем массив

    int newByte = 0;
    for (int i = bits - 1; i >= 0; i--)
    {
        if (i % 8 == 7 && i != bits - 1)
        {
            newByte++;
        }

        int pos = (i - n) / 8;
        int step = 7 - (i - n) % 8;

        if (pos >= 0 && (array[pos] & (1 << (7 - (i % 8)))))
        {
            array[newByte] |= (1 << step);
        }
        else
        {
            array[newByte] &= ~(1 << step);
        }
    }

    return *this;
}

// Операция сдвига влево (копия)
BitArray BitArray::operator<<(int n) const
{
    BitArray newBitArray = *this; // Создание копии
    newBitArray <<= n; // Используем тот же метод сдвига

    return newBitArray;
}

// Операция сдвига вправо (копия)
BitArray BitArray::operator>>(int n) const
{
    BitArray newBitArray = *this; // Создание копии
    newBitArray >>= n; // Используем тот же метод сдвига

    return newBitArray;
}