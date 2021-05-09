#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <ctime>

class Square{

private:
    int x;
    int y;
    int shipID;
    bool containShip;
    bool hasBeenShot;

public:
    /* Constructors */
    Square();
    Square(int x, int y, bool containShip, bool hasBeenShot, int shipID);
    ~Square() = default;

    /* Setters-Getters */
    int getX() const;
    int getY() const;
    int getContainShip() const;
    int getHasBeenShot() const;
    int getShipID() const;
    void setX(int x);
    void setY(int y);
    void setContainShip(bool containShip);
    void setHasBeenShot(bool hasBeenShot);
    void setShipID(int shipID);
};

#endif
