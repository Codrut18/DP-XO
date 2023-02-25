#include "Board.h"
#include <ctime>

#ifndef X_0_COMPUTER_H
#define X_0_COMPUTER_H

#endif //X_0_COMPUTER_H

class Computer{
    bool mark;

public:

    Computer(bool _mark);

    void setMark(bool);

    bool getMark();

    std::pair<int, int> generateRandomMove();

    void makeMove(Board &board);
};