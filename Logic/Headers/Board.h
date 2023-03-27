//
// Created by Vlad on 2/27/2023.
//

#ifndef LOGIC_BOARD_H
#define LOGIC_BOARD_H


#include <vector>

/**
 * @brief This class contains the information about the game board of a Tic Tac Toe
 * @width represents the number of columns
 * @height represents the number of rows
 * @completed number of cells that have been marked in the current game
 * @board is a 2D array of integers - cells have value -1 if they are not marked,
 * 0 if they are marked with 0 and 1 if they are marker with X
 */
class Board {
    int width;
    int height;
    int completed;
    std::vector<std::vector<int>> board;

public:
    /**
     * @brief This is an empty constructor
     * initializes the @width and @height with 3
     * initializes @completed with 0
     * initializes @board array with -1 on every cell
     */
    Board();

    /**
     * checks if the @board is completely marked
     * @return true if it is completely marked
     * else @return false
     */
    bool boardIsFull(); //checks if the board is full

    int getHeight() const;

    void setHeight(int h);

    int getWidth() const;

    void setWidth(int w);

    const std::vector<std::vector<int>> &getBoard() const;

    void setBoard(const std::vector<std::vector<int>> &board);

    /**
     * Returns the current mark in a cell
     * @param line represents the cell's row
     * @param col represents the cell's column
     * @return integer
     */
    int getSign(int line, int col);

    /**
     * Place the mark in a specified cell
     * @param line represents the cell's row
     * @param col represents the cell's column
     * @param mark represents the mark
     */
    void placeSign(int line, int col, char mark);

    /**
     * Restores the @board to the initial state
     * Removes every mark and sets -1 in every cell
     */
    void reset();

    /**
     * Checks whether a mark can be placed in the specified cell or not
     * @param line represents the cell's row
     * @param col represents the cell's column
     * @return True in positive scenario else False
     */
    bool positionIsAvailable(int line, int col);

    /**
     * Displays the board in console
     */
    void PrintBoard();
};


#endif //LOGIC_BOARD_H
