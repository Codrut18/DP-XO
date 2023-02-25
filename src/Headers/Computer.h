#include "Board.h"

#ifndef X_0_COMPUTER_H
#define X_0_COMPUTER_H

#endif //X_0_COMPUTER_H

class Computer{
    bool mark;

public:

    Computer(bool _mark);

    void setMark(bool);

    bool getMark();

    void makeMove(Board &board);
};