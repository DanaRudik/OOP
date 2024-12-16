#include <iostream> // Подключаем библиотеку iostream
#include <cmath> // Подключаем библиотеку cmath

class BitArray
{

    public: 
    BitArray(); // конструктор
    ~BitArray(); // деструктор
    explicit BitArray(const int num_bits, unsigned long value); // явный конструктор
    BitArray(const BitArray& b); // конструктор копирования

    // Другие функции

    void swap(BitArray& b); // обмен
    void resize(int num_bits, bool value); // изменение размера
    void clear(); // очистка
    void push_back(bool bit); // добавление одного бита

    // Логические операторы

    BitArray& operator&=(const BitArray& b); // логическое "И"
    BitArray& operator|=(const BitArray& b); // логическое "ИЛИ"
    BitArray& operator^=(const BitArray& b); // "ИСКЛЮЧАЮЩЕЕ ИЛИ"
    BitArray operator~() const; // инверсия

    // Сдвиговые операторы

    BitArray& operator<<=(int n); // сдвиг влево
    BitArray& operator>>=(int n); // сдвиг вправо
    BitArray operator<<(int n) const; // копия сдвига влево
    BitArray operator>>(int n) const; // копия сдвига вправо
 
    // Сеттеры

    BitArray& set(int n, bool val); // Устанавливаем бит с индексом n в значение val
    BitArray& set(); // Заполняем массив true
    BitArray& reset(int n); // Устанавливаем бит с индексом n в false
    BitArray& reset(); // Заполняем массив false

    // Проверки

    bool any() const; // есть ли единицы?
    bool none() const; // нет ли единиц?
    int count() const; // количество единиц
    bool operator[](int i) const; // значение по индексу
    int size() const; // размер
    bool empty() const; // пуст ли массив?
    std::string to_string() const; // представление массива в виде строки
    
    unsigned char getElement(int index) const {
        return array[index]; // Предполагается, что индекс валиден
    }

    private:
    int byte; // количество байт
    unsigned char *array; // массив битов
    int bits; // количество битов

};

// Операторы двух массивов

bool operator==(const BitArray & a, const BitArray & b); // равенство
bool operator!=(const BitArray & a, const BitArray & b); // неравенство
BitArray operator&(const BitArray& b1, const BitArray& b2); // логическое "И"
BitArray operator|(const BitArray& b1, const BitArray& b2); // логическое "ИЛИ"
BitArray operator^(const BitArray& b1, const BitArray& b2); // "ИСКЛЮЧАЮЩЕЕ ИЛИ"
