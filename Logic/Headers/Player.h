//
// Created by Iusaq on 2/27/2023.
//

#ifndef LOGIC_PLAYER_H
#define LOGIC_PLAYER_H


#include <vector>
#include "Board.h"

class Player {
    char mark = 'u';

public:
    Player(char s);

    void makeMove(int line, int col, std::vector<std::vector<int>> &board);

    void makeMove(int line, int col, Board &board);
};


#endif //LOGIC_PLAYER_H
