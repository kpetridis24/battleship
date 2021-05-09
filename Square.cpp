#include "Square.h"

Square::Square() {
    this->x = 0;
    this->y = 0;
    this->shipID = -1;
    this->containShip = false;
    this->hasBeenShot = false;
}

Square::Square(int x, int y, bool containShip, bool hasBeenShot, int shipID) {
    this->shipID = shipID;
    this->x = x;
    this-> y = y;
    this->containShip = containShip;
    this->hasBeenShot = hasBeenShot;
}

int Square::getX() const {
    return x;
}

int Square::getY() const {
    return y;
}

int Square::getContainShip() const {
    return containShip;
}

int Square::getHasBeenShot() const {
    return hasBeenShot;
}

int Square::getShipID() const{
    return shipID;
}

void Square::setX(int x) {
    this->x = x;
}

void Square::setY(int y) {
    this->y = y;
}

void Square::setContainShip(bool containShip1) {
    this->containShip = containShip1;
}

void Square::setHasBeenShot(bool hasBeenShot1) {
    this->hasBeenShot = hasBeenShot1;
}

void Square::setShipID(int shipID) {
    this->shipID = shipID;
}