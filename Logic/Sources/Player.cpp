//
// Created by Vlad on 2/27/2023.
//

#include "../Headers/Player.h"

Player::Player(char s) {
    this->mark = s;
}

void Player::makeMove(int line, int col, std::vector<std::vector<int>> &board) {
    if(board[line][col]!=-1)
        board[line][col] = this->mark;
}

void Player::makeMove(int line, int col, Board &board) {
    if(board.positionIsAvailable(line,col))
        board.placeSign(line,col, this->mark);
}

char Player::GetMark() const {
    return mark;
}
