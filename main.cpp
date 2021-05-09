#include <iostream>
#include "Square.h"
#include "Ship.h"
#include "Player.h"

int main(){

    std::string name =  "Kostas";
    Player player = Player(name, 0);
    player.addShip(0, 0, 5, 'U', 0);
    player.addShip(1, 1, 4, 'R', 1);
    player.addShip(4, 4, 3, 'U', 2);
    player.addShip(4, 9, 2, 'U', 3);
    player.guessSquare(0, 4);
    player.acceptHit(4, 9);
    player.acceptHit(5, 9);
    player.showState();
    std::cout<<"Done!"<<std::endl;
}





















