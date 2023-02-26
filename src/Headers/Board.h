#include<cstddef>
#ifndef X_0_BOARD_H
#define X_0_BOARD_H


class Board{
private:
    //board width/height/size
    const std::size_t bwidth = 3;
    const std::size_t bheight = 3;
    std::size_t rlSize = 0; //variable that increases everytime you place an object on the board (X/0)
    //used for verifying if thje table is full and game cannot be played anymore ( isFull() )
    short table[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
public:
    Board();

    bool placeMark(int line, int col, bool mark);

    short getSign(int line, int col);

    void displayBoard();

    bool isFull();

    bool positionIsAvailable(int, int);

};

#endif //X_0_BOARD_H