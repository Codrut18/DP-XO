//
// Created by Vlad on 2/21/2023.
//

#include "../Headers/Game.h"
#include <random>
#include <ctime>

void Game::checkGameState() {
    for (int l = 0; l < 3; l++)
            if (board.getSign(l,0) == board.getSign(l,1) && board.getSign(l,1) == board.getSign(l,2) && board.getSign(l,2) == 1)
            {
                this->winner = 1;
                stopGame();
            }
            else if (board.getSign(l,0) == board.getSign(l,1) && board.getSign(l,1) == board.getSign(l,2) && board.getSign(l,2) == 0)
            {
                this->winner = 0;
                stopGame();
            }

        for (int c = 0; c < 3; c++)
            if (board.getSign(0,c) == board.getSign(1,c) && board.getSign(1,c) == board.getSign(2,2) && board.getSign(2,2) == 1)
            {
                this->winner = 1;
                stopGame();
            }
            else if (board.getSign(0,c) == board.getSign(1,c) && board.getSign(1,c) == board.getSign(2,2) && board.getSign(2,2) == 0)
            {
                this->winner = 0;
                stopGame();
            }
    if (board.getSign(0,0) == board.getSign(1,1) && board.getSign(1,1) == board.getSign(2,2) && board.getSign(2,2) == 1)
    {
        this->winner = 1;
        stopGame();
    }
    else if (board.getSign(0,0) == board.getSign(1,1) && board.getSign(1,1) == board.getSign(2,2) && board.getSign(2,2) == 0)
    {
        std::cout<<"0 wins\n";
        this->winner = 0;
        stopGame();
    }

    if(board.getSign(0,2) == board.getSign(1,1) && board.getSign(1,1) == board.getSign(2,0) && board.getSign(2,0) == 1)
    {
        this->winner = 1;
        stopGame();
    }

    if(board.getSign(0,2) == board.getSign(1,1) && board.getSign(1,1) == board.getSign(2,0) && board.getSign(2,0) == 0)
    {
        std::cout<<"0 wins\n";
        this->winner = 0;
        stopGame();
    }

    if(this->nrOfTurns==9 && this->winner == -1)
    {
        std::cout<<"DRAW\n";
        this->winner = 2;
        stopGame();
    }
}

void Game::changeTurn() {
    this->xTurn = !this->xTurn;
    this->nrOfTurns++;
    checkGameState(); //verificam daca dupa ulima modificare a matricei board exista castigator
}

void Game::displayBoard() {
    for (int line = 0; line < 3; line++) {
        for (int col = 0; col < 3; col++) {
            if (board.getSign(line, col) == 1) {
                std::cout << " X";
            } else if (board.getSign(line, col) == 0) {
                std::cout << " O";
            } else {
                std::cout << "  ";
            }

            if (col < 2) {
                std::cout << "  | ";
            }
        }
        std::cout << std::endl;
        if (line < 2) {
            std::cout << "----|-----|----" << std::endl;
        }
    }
}

void Game::start(bool mark) {
    player = new Player(mark);
    computer = new Computer(!mark);
    gameActive = true;
    while(gameActive){

    }
}

void Game::stopGame() {
    gameActive = false;
}

std::pair<int, int> Game::generateRandomMove() {
    std::pair<int, int> pozitie;

    std::srand(std::time(0));
    int random_number = std::rand() % 9;

    pozitie.first = random_number/3;
    pozitie.second = random_number%3;

    while(board.getSign(pozitie.first, pozitie.second) != -1)
    {
        random_number = std::rand() % 9;

        pozitie.first = random_number/3;
        pozitie.second = random_number%3;
    }

    //std::cout<<pozitie.first<<" "<<pozitie.second;
    return pozitie;
}
