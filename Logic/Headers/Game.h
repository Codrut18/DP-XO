//
// Created by Iusaq on 2/27/2023.
//

#ifndef LOGIC_GAME_H
#define LOGIC_GAME_H


#include <memory>
#include "Player.h"
#include "Computer.h"
#include "Board.h"

class Game {
    //Player *player;
    Player *player;
    Computer *computer;
    Board *board;
    bool playerTurn = false;
    bool active = false;
    int winner = -1;

public:

    Game() = default;

    Game(char playerMark, char computerMark);

    Player *getPlayer() const;

    Computer *getComputer() const;

    void setPlayer(Player *player);

    Board *getBoard() const;

    void setBoard(Board *board);

    bool isPlayerTurn() const;

    void setIsPlayerTurn(bool isPlayerTurn);

    bool isGameActive() const;

    int checkWinner(); //returns -1 if there's no winner yet, 0 if 0 wins, 1 if X wins, 2 if it's DRAW

    void start();
};


#endif //LOGIC_GAME_H
