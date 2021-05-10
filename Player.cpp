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

bool Player::addShip(int startI, int startJ, int shipLen, char direction, int shipID) {

    switch(direction){
        case 'U':
            for (int i = 0, i2 = startI; i < shipLen; i++, i2++) {
                if (selfGrid[i2][startJ].getContainShip()) {
                    return false;
                }
            }
            for (int i = 0, i2 = startI; i < shipLen; i++, i2++) {
                selfGrid[i2][startJ].setContainShip(true);
                selfGrid[i2][startJ].setShipID(shipID);
                ships[shipID].shipBlocks[i].setX(i2);
                ships[shipID].shipBlocks[i].setY(startJ);
            }
            break;
        case 'R':
            for(int j = 0, j2 = startJ; j < shipLen; j++, j2++) {
                if (selfGrid[startI][j2].getContainShip()) {
                    return false;
                }
            }
            for(int j = 0, j2 = startJ; j < shipLen; j++, j2++){
                selfGrid[startI][j2].setContainShip(true);
                selfGrid[startI][j2].setShipID(shipID);
                ships[shipID].shipBlocks[j].setX(startI);
                ships[shipID].shipBlocks[j].setY(j2);
            }
            break;
        default:
            std::cout<<"Give valid direction!"<<std::endl;
    }
    return true;
}

void Player::showState() {

    std::cout<<name<<" stats:"<<std::endl;
    for(auto & ship : ships){
        //std::cout<<"Ship "<<ship.shipBlocks[0].getShipID()<<":"<<std::endl;
        for(int v = 0; v < ship.getShipSize(); v++){
            if(ship.shipBlocks[v].getHasBeenShot()) std::cout<<"X ";
            else std::cout<<"_ ";
        }
        std::cout<<std::endl;
    }
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

void Player::guessSquare(int I, int J) {
    enemyGrid[I][J].setHasBeenShot(true);
}

void Player::placeShips() {

    srand(time(nullptr));
    int dir, indexI, indexJ, shipLen;
    char direction[2] = {'U', 'R'};
    std::cout << "Placing "<<name<<"'s ships..." << std::endl;

    for (int i = 0; i < NUM_SHIPS; i++) {
        shipLen = i + 2;
        ships[i] = Ship(shipLen, 0);

        while (true) {
            dir = rand() % 2;
            if (dir == 0) {
                indexI = rand() % (9 - shipLen);    //Place the ships in increasing-size order (i + 2)
                indexJ = rand() % 9;
            } else {
                indexI = rand() % 9;
                indexJ = rand() % (9 - shipLen);
            }
            if (addShip(indexI, indexJ, shipLen, direction[dir], i)) break;
        }
    }
}

void Player::showShipPlacement() {
    for(int i = 0; i < NUM_SHIPS; i++){
        std::cout<<"Ship "<<i<<std::endl;
        for(int j = 0; j < ships[i].getShipSize(); j++){
            std::cout<<"("<<ships[i].shipBlocks[j].getX()<<", "<<ships[i].shipBlocks[j].getY()<<") ";
        }
        std::cout<<std::endl;
    }
}
