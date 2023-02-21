#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
    int board[3][3];
    bool xTurn = false;
    int nrOfTurns;

    void checkGameState();

    void changeTurn();
};

