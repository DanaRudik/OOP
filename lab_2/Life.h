#include <iostream>
#include <fstream>
#include <set>
#include "Field.h"

class Life {
public:
    std::set<int> _birth;
    std::set<int> _survival;
    Grid _grid;
    int _iteration;

public:
    Life();

    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename);

    void tick(const int n);
    void showHelp() const;

    void setRules(const std::string &ruleLine);
    void setGridSize(const std::string &sizeLine);

    void printGrid();
};