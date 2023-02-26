#include "SFML/Graphics.hpp"
#include "Computer.h"
#include "Player.h"
#include <iostream>

/*
 * board-ul initial este o matrice 3x3 cu valoarea -1 peste tot
 * avem o variabila xTurn - daca xTurn este true => este randul lui X, altfel este randul lui 0
 * functia placeSymbol ia ca parametrii pozitia unde playerul/computerul plaseaza un symbol(linia si coloana)
 *  -daca pozitia este ocupata deja nu se va intampla nimic
 *  -daca pozitia nu este ocupata aceasta va primi valoarea lui xTurn
 *  daca valoarea lui board[l][c]==1 inseamna ca acolo este pus deja un X
 *  daca board[l][c]==0 insemana ca acolo se afla 0
 *  functia checkGameState verifica daca exista winner, ar trebui apelata la fiecare modificare a matricei board
 *  avem o variabila nrOfTurns - retine cate tururi s-au jucat - daca s-au jucat 9 tururi si nu a fost gasit castigator inseamna ca avem DRAW
 *
 *  scriu acest comentariu ca sa fac un commit de test fiindca am o problema cu usernamenul
 */


class Game {
public:
    //int board[3][3]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
    Board *board;
    Player *player = nullptr;
    Computer *computer = nullptr;

    bool playerTurn = true;

    bool gameActive = false;

    int winner = -1;

    void start();

    void checkGameState();

    void changeTurn();

    void displayBoard();

    void stopGame();

};

