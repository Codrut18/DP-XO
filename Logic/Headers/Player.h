//
// Created by Vlad on 2/27/2023.
//

#ifndef LOGIC_PLAYER_H
#define LOGIC_PLAYER_H


#include <vector>
#include "Board.h"

/**
 * @brief This class contains information about the player
 * @mark represents with what sign the player plays
 */
class Player {
    char mark = 'u';

public:
    /**
     * @brief This is a constructor that takes as a parameter the sign the player has
     * @param s represents the player will play with
     * initializes @mark with the value of the parameter
     */
    Player(char s);

    /**
     *@brief This function places a sign on the game board at the specified position
     * @param line represents the line on which the player is going to place a sign
     * @param col represents the column on which the player is going to place a sign
     * @param board represents the actual board in which the game is taking place
     */
    void makeMove(int line, int col, std::vector<std::vector<int>> &board);

    void makeMove(int line, int col, Board &board);

    /**
     * This is a getter for the mark of the player
     * @return the mark of the player
     */
    char GetMark() const;
};


#endif //LOGIC_PLAYER_H
