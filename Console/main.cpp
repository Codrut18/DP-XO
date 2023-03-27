#include <iostream>
#include "../Logic/Headers/IGame.h"

void InitMarks(IGame *&game) {
    bool succes = false;
    char mark;
    while (!succes) {
        std::cout << "Choose you mark (0 / X but only choose X for now):";
        std::cin >> mark;
        if (mark == 'X' || mark == 'x') {
            game = IGame::Produce('X','0');
            game->setIsPlayerTurn(true);
            succes = true;
        } else if (mark == '0') {
//            game = new Game('0', 'X');
//            game->setIsPlayerTurn(false);
//            succes = true;
                std::cout<<"Nu ai voie";
        } else {
            std::cout << "You have to choose between 0 and X\n";
            succes = false;
        }
    }
}

bool IsPositionValid(int line, int column) {
    if (line >= 0 && line < 3 && column >= 0 && column < 3)
        return true;
    return false;
}

void ChoosePosition(int &line, int &column) {
    //int tempLine, tempColumn;
    while (!IsPositionValid(line, column)) {
        std::cout << "Choose the line and the column you want to place your mark:";
        std::cin >> line >> column;
    }
}

int Play(IGame *game) {
    game->start();
    Board *board = game->getBoard();
    Player *player = game->getPlayer();
    Computer *computer = game->getComputer();
    int winner = -1;
    int line, column;
    while (game->isGameActive() && game->isPlayerTurn()) {
        line=-1, column=-1;
        board->PrintBoard();
        ChoosePosition(line, column);
        player->makeMove(line, column, *board);
        game->setIsPlayerTurn(false);
        std::pair<int, int> computerPos = computer->makeMove(line,column,board);
        board->placeSign(computerPos.first, computerPos.second, computer->GetMark());
        game->setIsPlayerTurn(true);
        system("CLS");
        board->PrintBoard();
        winner = game->checkWinner();
    }

    return winner;
}

void Result(IGame *game, int winner) {
    switch (winner) {
        case 0: {
            system("CLS");
            game->getBoard()->PrintBoard();
            std::cout << "0 Won the game \n";
            break;
        }
        case 1: {
            system("CLS");
            game->getBoard()->PrintBoard();
            std::cout << "X Won the game \n";
            break;
        }
        case 2: {
            system("CLS");
            game->getBoard()->PrintBoard();
            std::cout << "DRAW \n";
            break;
        }
        default:
            break;

    }
}

int main() {
    IGame *game = nullptr;
    InitMarks(game);
    Result(game,Play(game));
    return 0;
}