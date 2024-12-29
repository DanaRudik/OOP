#include <iostream>
#include "Field.h"





Grid::Grid() {}

Grid::Grid(int height, int width) : _height(height), _width(width),
    _cells(height, std::vector<Cell>(width)) {
}

int Grid::getHeight() const {
    return _height;
}

int Grid::getWidth() const {
    return _width;
}

int Grid::countNeighbors(int y, int x) {
    int count = 0;
    int ny, nx;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0) continue;

            ny = (y + dy + _height) % _height;
            nx = (x + dx + _width) % _width;
            if (_cells[ny][nx].isAlive()) {
                count++;
            }
        }
    }
    return count;
}

bool Grid::isAlive(const int y, const int x) {
    return _cells[y][x].isAlive();
}

bool Grid::isChange(const int y, const int x) {
    return _cells[y][x].isChange();
}

void Grid::setAlive(int y, int x, bool alive) {
    _cells[y][x].setAlive(alive);
}

void Grid::setChange(int y, int x, bool change) {
    _cells[y][x].setChange(change);
}

void Grid::print() {
    // Выводим верхнюю рамку
    std::cout << "+";
    for (int j = 0; j < _width; j++) {
        std::cout << "-"; // Символ рамки
    }
    std::cout << "+" << std::endl;

    // Выводим содержимое поля с боковыми рамками
    for (int i = 0; i < _height; i++) {
        std::cout << "|"; // Боковая рамка слева
        for (int j = 0; j < _width; j++) {
            std::cout << ((_cells[i][j].isAlive()) ? 'o' : ' '); // Содержимое ячейки
        }
        std::cout << "|"; // Боковая рамка справа
        std::cout << std::endl;
    }

    // Выводим нижнюю рамку
    std::cout << "+";
    for (int j = 0; j < _width; j++) {
        std::cout << "-"; // Символ рамки
    }
    std::cout << "+" << std::endl;
}
