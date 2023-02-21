//
// Created by Iusaq on 2/21/2023.
//

#include "Game.h"

void Game::checkGameState() {
    for (int l = 0; l < 3; l++)
        for (int c = 0; c < 3; c++)
            if (board[l][c] == board[l][c + 1] == board[l][c + 2] == 1)
            {
                std::cout << "X wins";
                //stop game
            }
            else if (board[l][c] == board[l][c + 1] == board[l][c + 2] == 0)
            {
                std::cout << "0 wins";
                //stop game
            }
    for (int l = 0; l < 3; l++)
        for (int c = 0; c < 3; c++)
            if (board[l][c] == board[l + 1][c] == board[l + 2][c] == 1)
            {
                std::cout << "X wins";
                //stop game
            }
            else if (board[l][c] == board[l + 1][c] == board[l + 2][c] == 0)
            {
                std::cout << "0 wins";
                //stop game
            }
    if (board[0][0] == board[1][1] == board[2][2] == 1)
    {
        std::cout<<"X wins";
        //stop game
    }
    else if (board[0][0] == board[1][1] == board[2][2] == 0)
    {
        std::cout<<"0 wins";
        //stop game
    }

    if(board[0][2] == board[1][1] == board[2][0] == 1)
    {
        std::cout<<"X wins";
        //stop game
    }

    if(board[0][2] == board[1][1] == board[2][0] == 0)
    {
        std::cout<<"0 wins";
        //stop game
    }

    if(this->nrOfTurns==9)
    {
        std::cout<<"DRAW";
        //stop game
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
