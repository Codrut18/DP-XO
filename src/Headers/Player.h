#include <string>
#include <iostream>
#include "Board.h"

#ifndef X_0_PLAYER_H
#define X_0_PLAYER_H
#endif //X_0_PLAYER_H


class Player
{
private:
    std::string name;
    bool mark;

public:
    Player(bool _mark);

    void makeMove(Board &board, int line, int col);

    void choosePlace();
};
