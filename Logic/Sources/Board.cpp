//
// Created by Iusaq on 2/27/2023.
//

#include "../Headers/Board.h"
#include <iostream>

Board::Board() {
    board.resize(3);
    for (int line = 0; line < 3; line++) {
        board[line].resize(3);
        for (int col = 0; col < 3; col++)
            board[line][col] = -1;
    }

    width = 3;
    height = 3;
    completed = 0;
}

bool Board::boardIsFull() {
    return completed == 9;
}

int Board::getHeight() const {
    return height;
}

void Board::setHeight(int h) {
    height = h;
}

int Board::getWidth() const {
    return width;
}

void Board::setWidth(int w) {
    width = w;
}

void Board::reset() {
    width = 3;
    height = 3;
    for (int line = 0; line < height; line++) {
        for (int col = 0; col < width; col++) {
            board[line][col] = -1;
        }
    }
}

const std::vector<std::vector<int>> &Board::getBoard() const {
    return board;
}

void Board::setBoard(const std::vector<std::vector<int>> &board) {
    Board::board = board;
}

int Board::getSign(int line, int col) {
    return this->board[line][col];
}

void Board::placeSign(int line, int col, char mark) {
    if (positionIsAvailable(line, col)) {
        switch (mark) {
            case 'X': {
                board[line][col] = 1;
                break;
            }
            case '0': {
                board[line][col] = 0;
                break;
            }
            default:
                break;
        }
    }
}

bool Board::positionIsAvailable(int line, int col) {
    return board[line][col] == -1;
}

void Board::PrintBoard() {
    system("CLS");
    std::cout<<'\n';
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == -1)
                std::cout << "_ ";
            else if (board[i][j] == 0)
                std::cout << "0 ";
            else if (board[i][j] == 1)
                std::cout << "X ";
        }
        std::cout<<"\n";
    }
    std::cout<<'\n';
}