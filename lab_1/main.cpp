#include <gtest/gtest.h>
#include <iostream>

// Основной тестируемый код
void printMessage() {
    std::cout << "Hello, from BitArray!\n";
}

// Тест, который проверяет вывод
TEST(PrintMessageTest, OutputCheck) {
    // Перенаправляем std::cout в строковый поток
    std::stringstream buffer;
    std::streambuf* prevCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    // Вызываем функцию, которая должна что-то напечатать
    printMessage();

    // Восстанавливаем стандартный cout
    std::cout.rdbuf(prevCoutBuffer);

    // Проверяем, что содержимое буфера соответствует ожиданиям
    EXPECT_EQ(buffer.str(), "Hello, from BitArray!\n");
}
