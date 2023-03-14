//
// Created by Iusaq on 2/27/2023.
//

#ifndef LOGIC_COMPUTER_H
#define LOGIC_COMPUTER_H


#include <vector>
#include "Board.h"

class Computer {
    char mark = 'u';

public:
    Computer(char s);

    std::pair<int,int> makeMove(int line, int col, Board* board);

    char GetMark() const;
};


#endif //LOGIC_COMPUTER_H
