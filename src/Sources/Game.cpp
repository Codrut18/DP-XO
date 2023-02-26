//
// Created by Vlad on 2/21/2023.
//

#include "../Headers/Game.h"
#include <random>

void Game::checkGameState() {
    for (int l = 0; l < 3; l++)
        if (board->getSign(l, 0) == board->getSign(l, 1) && board->getSign(l, 1) == board->getSign(l, 2) &&
            board->getSign(l, 2) == 1) {
            this->winner = 1;
            stopGame();
        } else if (board->getSign(l, 0) == board->getSign(l, 1) && board->getSign(l, 1) == board->getSign(l, 2) &&
                   board->getSign(l, 2) == 0) {
            this->winner = 0;
            stopGame();
        }

    for (int c = 0; c < 3; c++)
        if (board->getSign(0, c) == board->getSign(1, c) && board->getSign(1, c) == board->getSign(2, c) &&
            board->getSign(2, c) == 1) {
            this->winner = 1;
            stopGame();
        } else if (board->getSign(0, c) == board->getSign(1, c) && board->getSign(1, c) == board->getSign(2, c) &&
                   board->getSign(2, c) == 0) {
            this->winner = 0;
            stopGame();
        }
    if (board->getSign(0, 0) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 2) &&
        board->getSign(2, 2) == 1) {
        this->winner = 1;
        stopGame();
    } else if (board->getSign(0, 0) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 2) &&
               board->getSign(2, 2) == 0) {
        std::cout << "0 wins\n";
        this->winner = 0;
        stopGame();
    }

    if (board->getSign(0, 2) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 0) &&
        board->getSign(2, 0) == 1) {
        this->winner = 1;
        stopGame();
    }

    if (board->getSign(0, 2) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 0) &&
        board->getSign(2, 0) == 0) {
        std::cout << "0 wins\n";
        this->winner = 0;
        stopGame();
    }

    if (board->isFull() && this->winner == -1) {
        std::cout << "DRAW\n";
        this->winner = 2;
        stopGame();
    }
}

void Game::start() {
    board = new Board();
    char symbol = 'c';
    do {
        std::cout << "\nAlegeti dintre X si 0 un simbol cu care sa jucati:";
        std::cin >> symbol;
        if (symbol != 'X' && symbol != '0')
            std::cout << "Nu ati introdus un simbol corect. Mai incercati!";
    } while (symbol != 'X' && symbol != '0');

    switch (symbol) {
        case 'X': {
            player = new Player(1);
            computer = new Computer(0);
            break;
        };
        case '0': {
            player = new Player(0);
            computer = new Computer(1);
            break;
        };
    }

    gameActive = true;

    bool playerTurn = player->getMark();

    while (gameActive) {
        if (playerTurn == false) {
            computer->makeMove(*board);
            checkGameState();
            playerTurn = !playerTurn;
        } else if (playerTurn == true) {
            board->displayBoard();
            int line, col;
            bool available = false;
            do {
                std::cout << "\nEste randul dvs: \n";
                std::cin >> line >> col;
                if (board->positionIsAvailable(line, col)) {
                    available = true;
                    player->makeMove(*board, line, col);
                    checkGameState();
                    playerTurn = false;
                } else {
                    std::cout << "Incercati o pozitie valabila:\n";
                }
            } while (available == false);
        }
    }

    board->displayBoard();
    switch (this->winner) {
        case 2: {
            std::cout << "\nEGALITATE\n";
            break;
        };
        case 0: {
            if (this->player->getMark() == 0) {
                std::cout << "\nFELICITARI! Ati castigat!\n";
            } else {
                std::cout << "\nATI PIERDUT! MAI INCERCATI!\n";
            }
            break;
        };
        case 1: {
            if (this->player->getMark() == 1) {
                std::cout << "\nFELICITARI! Ati castigat!\n";
            } else {
                std::cout << "\nATI PIERDUT! MAI INCERCATI!\n";
            }
        }
    }
}

void Game::stopGame() {
    gameActive = false;
}

