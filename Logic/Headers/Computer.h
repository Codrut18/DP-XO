//
// Created by Vlad on 2/27/2023.
//

#ifndef LOGIC_COMPUTER_H
#define LOGIC_COMPUTER_H

#include <vector>
#include "Board.h"

/**
 * @brief This class simulate the computer's way of playng Tic Tac Toe
 */
class Computer {
    /**@mark is the current sign the computer is playing Tic Tac Toe with. By default it is 'u' which stands for 'undefined' */
    char mark = 'u';

public:
    /**
     * Initializes the Computer class
     * @param s represents the symbol computer instance will play with
     */
    Computer(char s);

    /**
     * This is a class that simulates the move made by a computer on a given board
     * @param board
     * @return the position where computer placed a mark
     */
    std::pair<int,int> makeMove(Board *board);

    /**
     * Simple Getter
     * @return the sign the computer is playing with
     */
    char GetMark() const;
};


#endif //LOGIC_COMPUTER_H
