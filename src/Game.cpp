//
// Created by Vlad on 2/21/2023.
//

#include "Game.h"

void Game::checkGameState() {
    for (int l = 0; l < 3; l++)
            if (board[l][0] == board[l][1] && board[l][1] == board[l][2] && board[l][2] == 1)
            {
                std::cout << "X wins";
                stopGame();
            }
            else if (board[l][0] == board[l][1] && board[l][1] == board[l][2] && board[l][2] == 0)
            {
                std::cout << "0 wins";
                stopGame();
            }

        for (int c = 0; c < 3; c++)
            if (board[0][c] == board[1][c] && board[1][c] == board[2][c] && board[2][c] == 1)
            {
                std::cout << "X wins";
                //stop game
                stopGame();
            }
            else if (board[0][c] == board[1][c] && board[1][c] == board[2][c] && board[2][c] == 0)
            {
                std::cout << "0 wins";
                //stop game
                stopGame();
            }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 1)
    {
        std::cout<<"X wins";
        //stop game
        stopGame();
    }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 0)
    {
        std::cout<<"0 wins";
        //stop game
        stopGame();
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 1)
    {
        std::cout<<"X wins";
        //stop game
        stopGame();
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 0)
    {
        std::cout<<"0 wins";
        //stop game
        stopGame();
    }

    if(this->nrOfTurns==9)
    {
        std::cout<<"DRAW";
        //stop game
        stopGame();
    }
}

void Game::changeTurn() {
    this->xTurn = !this->xTurn;
    this->nrOfTurns++;
    checkGameState(); //verificam daca dupa ulima modificare a matricei board exista castigator
}

void Game::placeSymbol(int l, int c) {
    if(board[l][c]!=-1)
        return;
    board[l][c] = xTurn;
    changeTurn();
}

bool Game::positionIsTouched(int l, int c) {
    if(board[l][c]!=-1)
        return false;
    return true;
}

void Game::displayBoard() {
    for (int line = 0; line < 3; line++) {
        for (int col = 0; col < 3; col++) {
            if (board[line][col] == 1) {
                std::cout << " X";
            } else if (board[line][col] == 0) {
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

void Game::start() {
    gameActive = true;
    while(gameActive){
        if(xTurn==true)
            std::cout<<"Este randul lui X :";
        else std::cout<<"Este randul lui 0: ";

        int l, c;
        std::cin>>l>>c;
        this->placeSymbol(l,c);
        std::cout<<'\n';

        if(gameActive)
            displayBoard();
        else{
            std::cout<<"----------FINAL BOARD------------\n";
            displayBoard();
        }
    }
}

void Game::stopGame() {
    gameActive = false;
}
