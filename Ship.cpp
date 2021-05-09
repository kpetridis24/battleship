#include "Ship.h"

Ship::Ship() {
    this->shipSize = 0;
    this->shipBlocks = nullptr;
    this->selfWounds = 0;
}

Ship::Ship(int shipSize, int selfWounds) {
    this->shipSize = shipSize;
    this->selfWounds = selfWounds;
    shipBlocks = new Square[shipSize];
}

int Ship::getShipSize() const {
    return shipSize;
}

int Ship::getSelfWounds() const {
    return selfWounds;
}

void Ship::setShipSize(int shipSize1) {
    this->shipSize = shipSize1;
}

void Ship::setSelfWounds(int selfWounds1) {
    this->selfWounds = selfWounds1;
}

bool Ship::isOnSquare(Square s) {

    if(!shipBlocks){
        std::cout<<"Ship squares are NOT initialized!"<<std::endl;
        exit(1);
    }

    for(int j = 0; j < shipSize; j++){
        if(shipBlocks[j].getX() == s.getX() && shipBlocks[j].getY() == s.getY()){
            return true;
        }
    }
    return false;
}

bool Ship::isSink() const {
    if(selfWounds == shipSize) return true;
    return false;
}


