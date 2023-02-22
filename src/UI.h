#include <SFML/Graphics.hpp>
#include "Game.h"

#ifndef X_0_UI_H
#define X_0_UI_H

//SFML
//Created a table of buttons. Each button has 3 textures: empty_button, x_button and o_button
//Textures will change after the players click of the buttons
//Used logic from "Game" class in order to verify the game state

const int TABLE_WIDTH = 3;
const int TABLE_HEIGHT = 3;
const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 150;
const int BUTTON_SPACING = 10;
const int BOARD_PADDING = 100;
const int BOARD_WIDTH = TABLE_WIDTH * (BUTTON_WIDTH + BUTTON_SPACING) - BUTTON_SPACING + BOARD_PADDING * 2;
const int BOARD_HEIGHT = TABLE_HEIGHT * (BUTTON_HEIGHT + BUTTON_SPACING) - BUTTON_SPACING + BOARD_PADDING * 2;
const int LINE_THICKNESS = 10;

class UI {


public:

    int board[TABLE_HEIGHT][TABLE_WIDTH];
    sf::RectangleShape buttons[TABLE_HEIGHT][TABLE_WIDTH];
    sf::Texture buttonTextures[3];

    void gameBoard();

    void playGame();
    Game game;
};


#endif //X_0_UI_H
