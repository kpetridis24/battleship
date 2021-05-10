#include <iostream>
#include "Square.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"

int main()
{
    std::string name1, name2;
    name1 = "Kostas";
    name2 = "Mitspap";

    Game battleShip = Game(0, name1, name2);
    battleShip.play();
}





















