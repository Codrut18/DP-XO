#include "../Headers/Player.h"

Player::Player(bool _mark) {
    this->mark = _mark;
}

void Player::makeMove(Board &board, int line, int col) {
    board.placeMark(line, col, this->mark);
}
