#include <iostream>
#include "gtest/gtest.h"
#include "BitArray.h" 

// Тестирование конструктора и базовых методов
TEST(BitArrayTest, ConstructorsAndBasicMethods) {
    BitArray testArray1;  // Инициализация для теста
    ASSERT_EQ(testArray1.size(), 0);
    EXPECT_TRUE(testArray1.empty());

    BitArray testArray(9, 5);  // Тестируем явный конструктор
    EXPECT_EQ(testArray.size(), 2);
    EXPECT_EQ(testArray.count(), 2);

    std::string a = "000000101";
    std::string& strRef = testArray.to_string();
    EXPECT_EQ(strRef, a);
    delete &strRef;

    BitArray copyArray(testArray);  // Тестируем копирующий конструктор
    EXPECT_EQ(testArray.to_string(), copyArray.to_string());
    EXPECT_EQ(copyArray.size(), 2);
}

// Тестирование операций с битами и изменением размера
TEST(BitArrayTest, OperationsAndResize) {
    BitArray testArray(5, 0b10101);  // Подготовка массива

    // Тестирование метода resize
    testArray.resize(3, 0);
    EXPECT_EQ(testArray.size(), 3);
    EXPECT_EQ(testArray.to_string(), "101");

    // Тестирование push_back
    testArray.push_back(true);
    testArray.push_back(false);
    testArray.push_back(true);
    
    EXPECT_EQ(testArray.size(), 6);
    EXPECT_EQ(testArray.to_string(), "101101");

    // Тестирование swap
    BitArray bitArray2(8, 0xAA);
    bitArray2.swap(testArray);
    EXPECT_EQ(testArray.to_string(), "01010101");
    EXPECT_EQ(bitArray2.to_string(), "10110100");
}

// Тестирование очистки и логических операций
TEST(BitArrayTest, ClearAndLogicalOperations) {
    BitArray testArray(8, 0xFF);  // Подготовка массива
    testArray.clear();
    EXPECT_EQ(testArray.size(), 0);
    EXPECT_TRUE(testArray.empty());

    BitArray a(8, 0b10101010);
    BitArray b(8, 0b11001100);
    
    EXPECT_EQ((a & b).to_string(), "10001000");
    EXPECT_EQ((a | b).to_string(), "11101110");
    EXPECT_EQ((a ^ b).to_string(), "01100110");
    EXPECT_EQ((~a).to_string(), "01010101");
}

// Тестирование сдвигов
TEST(BitArrayTest, Shifts) {
    BitArray testArray(8, 0b10110011);  // Подготовка массива

    testArray <<= 1;
    EXPECT_EQ(testArray.to_string(), "01100110"); 

    testArray >>= 1;
    EXPECT_EQ(testArray.to_string(), "00110011"); 

    BitArray baZero(8, 0b00000000);
    baZero <<= 3; 
    EXPECT_EQ(baZero.to_string(), "00000000");
}

// Тестирование установки битов
TEST(BitArrayTest, SetBits) {
    BitArray testArray(8, 0b00000000);  // Подготовка массива
    
    testArray.set(0, true);
    EXPECT_EQ(testArray.to_string(), "10000000");

    testArray.set(3, true);
    EXPECT_EQ(testArray.to_string(), "10010000");

    testArray.set(7, true);
    EXPECT_EQ(testArray.to_string(), "10010001");

    testArray.set(5, true);
    EXPECT_EQ(testArray.to_string(), "10010101");
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
