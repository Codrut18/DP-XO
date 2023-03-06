//
// Created by Iusaq on 2/27/2023.
//

#include "../Headers/Game.h"

Player *Game::getPlayer() const {
    return player;
}

void Game::setPlayer(Player *player) {
    Game::player = player;
}

Board *Game::getBoard() const {
    return board;
}

void Game::setBoard(Board *board) {
    Game::board = board;
}

bool Game::isPlayerTurn() const {
    return playerTurn;
}

void Game::setIsPlayerTurn(bool isPlayerTurn) {
    Game::playerTurn = isPlayerTurn;
}

bool Game::isGameActive() const {
    return active;
}

Game::Game(char playerMark, char computerMark) {
    player = new Player(playerMark);
    computer = new Computer(computerMark);

    if (playerMark == 'X')
        playerTurn = true;
    else playerTurn = false;

    board = new Board();
}

void Game::start() {
    active = true;
    board->reset();
}

int Game::checkWinner() {
    for (int line = 0; line < 3; line++) {
        if (board->getSign(line, 0) == board->getSign(line, 1) && board->getSign(line, 1) == board->getSign(line, 2) &&
            board->getSign(line, 2) == 0) {
            winner = 0;
            active = false;
        } else if (board->getSign(line, 0) == board->getSign(line, 1) &&
                   board->getSign(line, 1) == board->getSign(line, 2) && board->getSign(line, 2) == 1) {
            winner = 1;
            active = false;
        }
    }
    for (int col = 0; col < 3; col++) {
        if (board->getSign(0, col) == board->getSign(1, col) && board->getSign(1, col) == board->getSign(2, col) &&
            board->getSign(2, col) == 0) {
            winner = 0;
            active = false;
        } else if (board->getSign(0, col) == board->getSign(1, col) && board->getSign(1, col) == board->getSign(2, col) &&
                   board->getSign(2, col) == 1) {
            winner = 1;
            active = false;
        }
    }

    if(winner==-1) {
        if (board->getSign(0, 0) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 2) &&
            board->getSign(2, 2) == 0) {
            winner = 0;
            active = false;
        } else if (board->getSign(0, 0) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 2) &&
                   board->getSign(2, 2) == 1) {
            winner = 1;
            active = false;
        } else if (board->getSign(0, 2) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 0) &&
                   board->getSign(2, 0) == 0) {
            winner = 0;
            active = false;
        } else if (board->getSign(0, 2) == board->getSign(1, 1) && board->getSign(1, 1) == board->getSign(2, 0) &&
                   board->getSign(2, 0) == 1) {
            winner = 1;
            active = false;
        } else if (board->boardIsFull()) {
            winner = 2;
            active = false;
        }
    }

    return winner;
}

Computer *Game::getComputer() const {
    return computer;
}
