#include "Cell.h"

Cell::Cell() : _alive(false), _change(false) {}

bool Cell::isAlive() {
    return _alive;
}

bool Cell::isChange() {
    return _change;
}

void Cell::setAlive(const bool alive) {
    _alive = alive;
}

void Cell::setChange(const bool change) {
    _change = change;
}