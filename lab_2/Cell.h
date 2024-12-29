class Cell {
private:
    bool _alive;
    bool _change;

public:
    Cell();

    bool isAlive();
    bool isChange();

    void setAlive(const bool alive);
    void setChange(const bool change);
};