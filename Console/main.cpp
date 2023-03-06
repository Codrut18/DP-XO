#include <iostream>
#include "../Logic/Headers/Game.h"

void InitMarks(Game *&game) {
    bool succes = false;
    char mark;
    while (!succes) {
        std::cout << "Choose you mark (0 / X):";
        std::cin >> mark;
        if (mark == 'X' || mark == 'x') {
            game = new Game('X', '0');
            succes = true;
        } else if (mark == '0') {
            game = new Game('0', 'X');
            succes = true;
        } else {
            std::cout << "You have to choose between 0 and X\n";
            succes = false;
        }
    }
}

void Play(Game *game) {
    game->start();
    Board *board = game->getBoard();
    Player *player = game->getPlayer();
    Computer *computer = game->getComputer();
    board->placeSign(1,1,player->GetMark());
    board->placeSign(2,2,computer->GetMark());
    board->PrintBoard();

    game->checkWinner();
}

int main() {
    Game *game = nullptr;
    InitMarks(game);
    Play(game);
    return 0;
}