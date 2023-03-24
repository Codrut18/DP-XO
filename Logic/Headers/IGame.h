//
// Created by Iusaq on 3/24/2023.
//

#ifndef UI_IGAME_H
#define UI_IGAME_H

#include "Player.h"
#include "Computer.h"
#include "Board.h"

class IGame {
public:
    virtual ~IGame() {}

    virtual Player *getPlayer() const = 0;

    virtual Computer *getComputer() const = 0;

    virtual void setPlayer(Player *player) = 0;

    virtual Board *getBoard() const = 0;

    virtual void setBoard(Board *board) = 0;

    virtual bool isPlayerTurn() const = 0;

    virtual void setIsPlayerTurn(bool isPlayerTurn) = 0;

    virtual bool isGameActive() const = 0;

    virtual int checkWinner() = 0; //returns -1 if there's no winner yet, 0 if 0 wins, 1 if X wins, 2 if it's DRAW
    virtual void start() = 0;

    static IGame *Produce(char playerMark, char computerMark);
};


#endif //UI_IGAME_H
