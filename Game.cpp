#include "Game.h"

Game::Game() {
    this->round = 0;
    this->p1 = Player();
    this->p2 = Player();
}

Game::Game(int round, std::string name1, std::string name2) {
    this->round = round;
    this->p1 = Player(name1, 0);
    this->p2 = Player(name2, 0);
}

int Game::getRound() const {
    return round;
}

void Game::setRound(int round) {
    this->round = round;
}

void Game::displayGameState() {
    std::cout<<"Game Round: "<<round<<std::endl<<std::endl;
    p1.showState();
    std::cout<<std::endl;
    p2.showState();
}

void Game::play() {

    srand(time(nullptr));
    std::cout<<"Game starting..."<<std::endl<<std::endl;
    p1.placeShips();
    p2.placeShips();
    std::cout<<std::endl;
    std::cout<<p1.getName()<<" ship positions!"<<std::endl;
    p1.showShipPlacement();
    std::cout<<p2.getName()<<" ship positions!"<<std::endl;
    p2.showShipPlacement();
    int idxI, idxJ;

    while(true) {
        std::cout<<"========================"<<std::endl;
        displayGameState();
        if (p1.getSinkedShips() == NUM_SHIPS){
            std::cout<<std::endl;
            std::cout<<p2.getName()<<" WINS!!!"<<std::endl;
            break;
        }
        else if(p2.getSinkedShips() == NUM_SHIPS){
            std::cout<<std::endl;
            std::cout<<p1.getName()<<" WINS!!!"<<std::endl;
            break;
        }

        // Player 1 turn
        while(true){
            idxI = rand() % 9;
            idxJ = rand() % 9;
            if(!p2.selfGrid[idxI][idxJ].getHasBeenShot()){
                p1.guessSquare(idxI, idxJ);
                p2.acceptHit(idxI, idxJ);
                break;
            }
        }

        // Player 2 turn
        while(true){
            idxI = rand() % 9;
            idxJ = rand() % 9;
            if(!p1.selfGrid[idxI][idxJ].getHasBeenShot()){
                p2.guessSquare(idxI, idxJ);
                p1.acceptHit(idxI, idxJ);
                break;
            }
        }

        this->round++;
        std::cout<<std::endl;
    }
}

