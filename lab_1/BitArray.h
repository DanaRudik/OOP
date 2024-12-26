#include <iostream> // Подключаем библиотеку iostream
#include <cmath> // Подключаем библиотеку cmath

class BitArray
{
    public: 

    // Constuctors
    BitArray(); // конструктор
    ~BitArray(); // деструктор
    explicit BitArray(const int num_bits, unsigned long value); // явный конструктор
    BitArray(const BitArray& b); // копирования

    // Manipulation
    void swap(BitArray& b); // обмен
    void resize(int num_bits, bool value); // изменение размера
    void clear(); // очистка
    void push_back(bool bit); // добавление одного бита

    // Operators сохраняет результат в текущий
    BitArray& operator&=(const BitArray& b); // логическое "И"
    BitArray& operator|=(const BitArray& b); // логическое "ИЛИ"
    BitArray& operator^=(const BitArray& b); // "ИСКЛЮЧАЮЩЕЕ ИЛИ"
    BitArray operator~() const; // инверсия

    BitArray& operator<<(int n); // копия сдвига влево
    BitArray& operator>>(int n); // копия сдвига вправо
 
    // Сеттеры
    BitArray& set(int n); // Устанавливаем бит с индексом n в значение val
    BitArray& set(); // Заполняем массив true
    BitArray& reset(int n); // Устанавливаем бит с индексом n в false
    BitArray& reset(); // Заполняем массив false

    // Проверки

    bool any() const; // есть ли единицы?
    bool none() const; // нет ли единиц?
    int count() const; // количество единиц
    bool operator[](int i) const; // значение по индексу
    int size() const; // размер
    bool empty() const; // пустота
    std::string& to_string() const; // представление массива в виде строки

    private:
    unsigned char *array; // массив битов
    int byte; // количество байт
    int bits; // количество битов

};

// Операторы для двух массивов
bool operator==(const BitArray & a, const BitArray & b); // равенство
bool operator!=(const BitArray & a, const BitArray & b); // неравенство
BitArray operator&(const BitArray& b1, const BitArray& b2); // логическое "И"
BitArray operator|(const BitArray& b1, const BitArray& b2); // логическое "ИЛИ"
BitArray operator^(const BitArray& b1, const BitArray& b2); // "ИСКЛЮЧАЮЩЕЕ ИЛИ"
