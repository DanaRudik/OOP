#include <iostream>
#include "gtest/gtest.h"
#include "BitArray.h" 

// Тестирование конструктора и базовых методов
TEST(BitArrayTest, ConstructorsAndBasicMethods) {
    BitArray testArray1;  // Инициализация для теста
    ASSERT_EQ(testArray1.size(), 0);
    EXPECT_EQ(testArray1.any(), 0);
    EXPECT_TRUE(testArray1.empty());

    BitArray testArray(9, 5);  //явный конструктор
    EXPECT_EQ(testArray.size(), 9);
    EXPECT_EQ(testArray.count(), 2);

    EXPECT_EQ(testArray.to_string(), "000000101");

    BitArray copyArray(testArray);  //копирующий конструктор
    EXPECT_EQ(testArray.to_string(), copyArray.to_string());
    EXPECT_TRUE((testArray == copyArray));
    EXPECT_EQ(copyArray.size(), 9);
}

// Тестирование операций с битами и изменением размера
TEST(BitArrayTest, OperationsAndResize) {
    BitArray testArray(5, 0b10101);  // Подготовка массива

    //resize
    testArray.resize(4, 0);
    EXPECT_EQ(testArray.size(), 4);
    EXPECT_EQ(testArray.to_string(), "0101");

    //push_back
    testArray.push_back(true);
    EXPECT_EQ(testArray.to_string(), "01011");
    testArray.push_back(false);
    EXPECT_EQ(testArray.to_string(), "010110");
    testArray.push_back(true);
    EXPECT_EQ(testArray.to_string(), "0101101");
    
    EXPECT_EQ(testArray.size(), 7);
    EXPECT_EQ(testArray.to_string(), "0101101");

    //swap
    BitArray testArray2(7, 0b1111111);
    testArray2.swap(testArray);
    EXPECT_EQ(testArray.to_string(), "1111111");
    EXPECT_EQ(testArray2.to_string(), "0101101");
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

//Тестирование сдвигов
TEST(BitArrayTest, Shifts) {
    BitArray testArray(6, 0b000010);  // Подготовка массива
    EXPECT_EQ(testArray.size(), 6);

    EXPECT_EQ((testArray << 1).to_string(), "000100");
    EXPECT_EQ((testArray >> 1).to_string(), "000010");  
}

//Тестирование установки битов
TEST(BitArrayTest, SetBits) {
    BitArray testArray(8, 0b00000001);  // Подготовка массива
    
    testArray.set(0);
    EXPECT_EQ(testArray.to_string(), "10000001");

    testArray.set(3);
    EXPECT_EQ(testArray.to_string(), "10010001");

    testArray.set();
    EXPECT_EQ(testArray.to_string(), "11111111");

    testArray.reset(0);
    EXPECT_EQ(testArray.to_string(), "01111111");

    testArray.reset();
    EXPECT_EQ(testArray.to_string(), "00000000");

}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
