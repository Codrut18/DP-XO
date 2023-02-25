#include "../Headers/Computer.h"
#include "../Headers/Board.h"

Computer::Computer(bool _mark) {
    this->mark = _mark;
}

void Computer::makeMove(Board &board) {

    auto pozitieMiscare = generateRandomMove();

    board.table[pozitieMiscare.first][pozitieMiscare.second] = mark;
}

std::pair<int, int> Computer::generateRandomMove() {

    Board board;

    std::pair<int, int> pozitie;

    std::srand(std::time(0));
    int random_number = std::rand() % 9;

    pozitie.first = random_number/3;
    pozitie.second = random_number%3;

    while(board.table[pozitie.first][pozitie.second] != -1)
    {
        random_number = std::rand() % 9;

        pozitie.first = random_number/3;
        pozitie.second = random_number%3;
    }

    //std::cout<<pozitie.first<<" "<<pozitie.second;
    return pozitie;
}

