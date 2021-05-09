#ifndef PLAYER_H
#define PLAYER_H
#include "Ship.h"
#define NUM_SHIPS 5
#define GRID_SIZE 10

class Player{

private:
    std::string name;
    int sinkedShips;
    Ship ships[NUM_SHIPS];
    Square selfGrid[GRID_SIZE][GRID_SIZE];
    Square enemyGrid[GRID_SIZE][GRID_SIZE];

public:
    /* Constructors */
    Player();
    Player(std::string name, int sinkedShips);
    ~Player() = default;

    /* Setters-Getters */
    std::string getName() const;
    int getSinkedShips() const;
    void setName(std::string name);
    void setSinkedShips(int sinkedShips);

    /* Functions */
    void addShip(int startI, int startJ, int shipLen, char direction, int shipID);
    void showState();
    bool acceptHit(int I, int J);
    bool guessSquare(int I, int J);
};

#endif
