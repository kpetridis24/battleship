#ifndef SHIP_H
#define SHIP_H
#include "Square.h"

class Ship{

private:
    int shipSize;
    int selfWounds;

public:
    /* Constructors */
    Square *shipBlocks;
    Ship();
    Ship(int shipSize, int selfWounds);
    ~Ship() = default;

    /* Setters-Getters */
    int getShipSize() const;
    int getSelfWounds() const;
    void setShipSize(int shipSize);
    void setSelfWounds(int selfWounds);

    /* Functions */
    bool isOnSquare(Square s);
    bool isSink() const;
};

#endif
