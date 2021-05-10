#ifndef GAME_H
#define GAME_H
#include "Player.h"

class Game{

private:
    int round;
    Player p1;
    Player p2;

public:
    /* Constructors */
    Game();
    explicit Game(int round, std::string name1, std::string name2);
    ~Game() = default;

    /* Getters-Setters */
    int getRound() const;
    void setRound(int round);

    /* Functions */
    void displayGameState();
    void play();
};

#endif
