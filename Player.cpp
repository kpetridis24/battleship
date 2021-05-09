#include "Player.h"

Player::Player() {
    this->name = "";
    this->sinkedShips = 0;
}

Player::Player(std::string name, int sinkedShips) {

    this->name = name;
    this->sinkedShips = sinkedShips;

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            selfGrid[i][j] = Square(i, j, false, false, -1);
            enemyGrid[i][j] = Square(i, j, false, false, -1);
        }
    }
}

std::string Player::getName() const {
    return name;
}

int Player::getSinkedShips() const {
    return sinkedShips;
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::setSinkedShips(int sinkedShips) {
    this->sinkedShips = sinkedShips;
}

void Player::addShip(int startI, int startJ, int shipLen, char direction, int shipID) {

    ships[shipID] = Ship(shipLen, 0);
    switch(direction){
        case 'U':
            for (int i = 0, i2 = startI; i < shipLen; i++, i2++) {
                ships[shipID].shipBlocks[i].setX(i2);
                ships[shipID].shipBlocks[i].setY(startJ);
                selfGrid[i2][startJ].setContainShip(true);
                selfGrid[i2][startJ].setShipID(shipID);
            }
            break;
        case 'R':
            for(int j = 0, j2 = startJ; j < shipLen; j++, j2++){
                ships[shipID].shipBlocks[j].setX(startI);
                ships[shipID].shipBlocks[j].setY(j2);
                selfGrid[startI][j2].setContainShip(true);
                selfGrid[startI][j2].setShipID(shipID);
            }
            break;
        default:
            std::cout<<"Give valid direction!"<<std::endl;
    }
}

void Player::showState() {
    std::cout<<"Player: "<<name<<std::endl;
    std::cout<<"Sink ships: "<<sinkedShips<<std::endl;
}

bool Player::acceptHit(int I, int J) {

    bool isHit = false;
    int shipId;
    selfGrid[I][J].setHasBeenShot(true);

    if(selfGrid[I][J].getContainShip()){
        isHit = true;
        shipId = selfGrid[I][J].getShipID();
        for(int i = 0; i < ships[shipId].getShipSize(); i++){
            if(ships[shipId].shipBlocks[i].getX() == I && ships[shipId].shipBlocks[i].getY() == J){
                ships[shipId].shipBlocks[i].setHasBeenShot(true);
                ships[shipId].setSelfWounds(ships[shipId].getSelfWounds() + 1);
                if(ships[shipId].isSink()) sinkedShips++;
                break;
            }
        }
    }
    return isHit;
}

bool Player::guessSquare(int I, int J) {

    bool isHit = false;
    enemyGrid[I][J].setHasBeenShot(true);
    return isHit;
}