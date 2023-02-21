#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
    bool b[3][3];
    bool xTurn = false;
    int nrOfTurns;

    void checkGameState();

    sf::RenderWindow mWindow;
};

