//
// Created by Iusaq on 2/27/2023.
//

#ifndef LOGIC_BOARD_H
#define LOGIC_BOARD_H


#include <vector>

class Board {
    int width;
    int height;
    int completed;
    std::vector<std::vector<int>> board;

public:
    Board();

    bool boardIsFull(); //checks if the board is full

    int getHeight() const;

    void setHeight(int h);

    int getWidth() const;

    void setWidth(int w);

    const std::vector<std::vector<int>> &getBoard() const;

    void setBoard(const std::vector<std::vector<int>> &board);

    int getSign(int line, int col);

    void placeSign(int line, int col, char mark);

    void reset();

    bool positionIsAvailable(int line, int col);

    void PrintBoard();
};


#endif //LOGIC_BOARD_H
