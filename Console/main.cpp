#include <iostream>
#include "../Logic/Headers/IGame.h"


/**
 * This function is used in the beginning of the game for establishing which sign the player uses
 * Whatever sign the player chooses, the computer gets the other one
 * If the player chooses another sign other than 'X' or '0' he gets an error and has to choose again
 * @param game represents the instance of the game
 */
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

/**
 * @brief This function returns True/False depending if the computer is allowed to place a sign on the specified position
 * @param line represents the line of the checked position
 * @param column represents the column of the checked position
 * @return True if the position where the computer places is valid
 * else False
 */
bool IsPositionValid(int line, int column) {
    if (line >= 0 && line < 3 && column >= 0 && column < 3)
        return true;
    else return false;

}

/**
 * @brief This function asks the player to place a sign on a position that is available
 * @param line represents the line where the player wants to place a sign
 * @param column represents the column where the player wants to place a sign
 */
void ChoosePosition(int &line, int &column) {
    //int tempLine, tempColumn;
    while (!IsPositionValid(line, column)) {
        std::cout << "Choose the line and the column you want to place your mark:";
        std::cin >> line >> column;
    }
}

/**
 * This is the function in which an instance of the game is called and used to play the game in the console
 * @param game represents the instance of the game
 * @return 0 for when the '0' sign wins, 1 when the 'X' sign wins or -1 for a draw
 */
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

/**
 * @brief This function prints the winner in console
 * @param game represents the instance of the game
 * @param winner stores information about who won(0 for '0' sign, 1 for 'X' sign and -1 for draw)
 */
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