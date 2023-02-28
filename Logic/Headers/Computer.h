//
// Created by Iusaq on 2/27/2023.
//

#ifndef LOGIC_COMPUTER_H
#define LOGIC_COMPUTER_H


#include <vector>

class Computer {
    char mark = 'u';

public:
    Computer(char s);

    void makeMove(std::vector<std::vector<int>> &board);
};


#endif //LOGIC_COMPUTER_H
