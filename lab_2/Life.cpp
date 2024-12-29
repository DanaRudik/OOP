#include "Life.h"
#include <iostream>
#include <string>


Life::Life() : _birth{3}, _survival{2, 3}, _grid(HEIGHT, WIDTH), _iteration(0) {
    _grid.setAlive(MID_HEIGHT, MID_WIDTH, true);
    _grid.setAlive(MID_HEIGHT + 1, MID_WIDTH, true);
    _grid.setAlive(MID_HEIGHT - 1, MID_WIDTH, true);
    _grid.setAlive(MID_HEIGHT, MID_WIDTH - 1, true);
    _grid.setAlive(MID_HEIGHT + 1, MID_WIDTH + 1, true);
}

void Life::loadFromFile(const std::string &filename) {
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        throw std::ios_base::failure("The file could not be opened: " + filename);
    }

    _iteration = 0;

    std::string line;
    while (!fin.eof()) {
        getline(fin, line);

        if (line[1] == 'R') {
            setRules(line);
        } else if (line[1] == 'S') {
            setGridSize(line);
            break;
        }
    }
    while (!fin.eof()) {
        getline(fin, line);

        if (line == "") {
            break;
        }

        int x = 0;
        int y = 0;

        // Не исключаются ошибки
        int i = 0;
        while (line[i] != ' ') {
            x = x * 10 + (line[i] - '0');
            i++;
        }
        i++;
        while (i < line.size()) {
            y = y * 10 + (line[i] - '0');
            i++;
        }
        _grid.setAlive(_grid.getHeight() - y, x - 1, true);
    }
    fin.close();
}

void Life::saveToFile(const std::string &filename) {
    std::ofstream fout(filename);

    if (!fout.is_open()) {
        throw std::ios_base::failure("The file could not be opened: " + filename);
    }

    fout << "#Life 1.06" << std::endl << "#R B";
    for (int elem : _birth) {
        fout << (char)(elem + '0');
    }
    fout << "/S";
    for (int elem : _survival) {
        fout << (char)(elem + '0');
    }
    fout << std::endl;

    fout << "#S H" << _grid.getHeight() << "/";
    fout << "W" << _grid.getWidth() << std::endl;

    for (int y = 0; y < _grid.getHeight(); y++) {
        for (int x = 0; x < _grid.getWidth(); x++) {
            if (_grid.isAlive(y, x)) {
                fout << (x + 1) << ' ' << (_grid.getHeight() - y) << std::endl;
            }
        }
    }

    std::cout << "The universe was successfully saved.\n" << std::endl;
    fout.close();
}

void Life::tick(const int n) {
    for (int i = 0; i < n; i++) {
        _iteration++;
        for (int y = 0; y < _grid.getHeight(); y++) {
            for (int x = 0; x < _grid.getWidth(); x++) {
                if (_grid.isAlive(y, x)) {
                    if (_survival.find(_grid.countNeighbors(y, x)) ==
                        _survival.end()) {
                        _grid.setChange(y, x, true);
                    }
                } else {
                    if (_birth.find(_grid.countNeighbors(y, x)) !=
                        _birth.end()) {
                        _grid.setChange(y, x, true);
                    }
                }
            }
        }
        for (int y = 0; y < _grid.getHeight(); y++) {
            for (int x = 0; x < _grid.getWidth(); x++) {
                if (_grid.isChange(y, x)) {
                    if (_grid.isAlive(y, x)) {
                        _grid.setAlive(y, x, false);
                    } else {
                        _grid.setAlive(y, x, true);
                    }
                    _grid.setChange(y, x, false);
                }
            }
        }
    }
}




void Life::setRules(const std::string &ruleLine) {
    int b = ruleLine.find('B');
    int s = ruleLine.find('S');

    int i = 1;
    while (ruleLine[b + i] != '/') {
        _birth.insert(ruleLine[b + i] - '0');
        i++;
    }
    i = 1;
    while (ruleLine[s + i] != '\n' && s + i < ruleLine.size()) {
        _survival.insert(ruleLine[s + i] - '0');
        i++;
    }
}

void Life::setGridSize(const std::string &sizeLine) {
    int h = sizeLine.find('H');
    int w = sizeLine.find('W');

    int height = 0;
    int width = 0;
    int i = 1;
    while (sizeLine[h + i] != '/') {
        height = height * 10 + (sizeLine[h + i] - '0');
        i++;
    }
    i = 1;
    while (sizeLine[w + i] != '\n' && w + i < sizeLine.size()) {
        width = width * 10 + (sizeLine[w + i] - '0');
        i++;
    }
    _grid = Grid(height, width);
}

void Life::printGrid() {
    _grid.print();
}

void Life::showHelp() const {
    std::cout << "+--------------------------+ Help +----------------------------+" << std::endl;
    std::cout << "| dump <filename>   | save the current universe to a file.     |" << std::endl;
    std::cout << "| tick <n>          | Execute n iterations of the simulation.  |" << std::endl;
    std::cout << "| exit              | Exit the game.                           |" << std::endl;
    std::cout << "| help              | Display command help.                    |" << std::endl;
    std::cout << "+--------------------------------------------------------------+" << std::endl;
}