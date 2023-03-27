//
// Created by Vlad on 2/27/2023.
//

#include "../Headers/Computer.h"
#include <ctime>
#include <random>

Computer::Computer(char s) {
    this->mark = s;
}

std::pair<int,int> Computer::makeMove(Board *board1) {
    auto board = board1->getBoard();
    std::pair<int, int> pozitie;

    std::srand(std::time(0));
    int random_number = std::rand() % 9;

    pozitie.first = random_number/3;
    pozitie.second = random_number%3;

    while(board[pozitie.first][pozitie.second] != -1)
    {
        random_number = std::rand() % 9;

        pozitie.first = random_number/3;
        pozitie.second = random_number%3;
    }

    return pozitie;
}

char Computer::GetMark() const {
    return mark;
}
