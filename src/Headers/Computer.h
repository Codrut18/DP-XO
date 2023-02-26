#include "Board.h"
#include <ctime>
#include <utility>

#ifndef X_0_COMPUTER_H
#define X_0_COMPUTER_H

#endif //X_0_COMPUTER_H

class Computer{
    bool mark;

public:

    Computer(bool _mark);

    bool getMark();

    std::pair<int, int> generateRandomMove(Board &board);

    void makeMove(Board &board);
};