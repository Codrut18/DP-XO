#include <iostream>
#include "../Headers/Board.h"

Board::Board()
{
    rlSize=0;
}

bool Board::placeMark(int line, int col, bool mark) {
    if(line<0 || line>this->bheight || col<0 || col>this->bwidth)
        return false;

    if(this->table[line][col]!=-1)
        return false;

    this->table[line][col] = (int)mark;
    this->rlSize++;
}

short Board::getSign(int line, int col) {
    return table[line][col];
}

void Board::displayBoard() {
    for (int line = 0; line < 3; line++) {
        for (int col = 0; col < 3; col++) {
            if (getSign(line, col) == 1) {
                std::cout << " X";
            } else if (getSign(line, col) == 0) {
                std::cout << " O";
            } else {
                std::cout << "  ";
            }

            if (col < 2) {
                std::cout << "  | ";
            }
        }
        std::cout << std::endl;
        if (line < 2) {
            std::cout << "----|-----|----" << std::endl;
        }
    }
}

bool Board::positionIsAvailable(int line, int col) {
    if(table[line][col]==-1)
        return true;
    return false;
}

bool Board::isFull() {
    return this->rlSize==9;
}


