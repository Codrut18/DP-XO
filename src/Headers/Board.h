#include<cstddef>
#include "Player.h"
#ifndef X_0_BOARD_H
#define X_0_BOARD_H
#endif //X_0_BOARD_H

class Board
{
private:
    //board width/height/size
    const std::size_t bwidth = 3;
    const std::size_t bheight = 3;
    const std::size_t bMaxSize = bwidth * bheight;
    std::size_t rlSize; //variable that increases everytime you place an object on the board (X/0)
    //used for verifying if thje table is full and game cannot be played anymore ( isFull() )
    short table[3][3];
public:
    Board();

    bool isFull();
    void Reset();
    void initTable();
};