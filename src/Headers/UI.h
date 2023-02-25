#include "SFML/Graphics.hpp"
#include "Game.h"

#ifndef X_0_UI_H
#define X_0_UI_H

//SFML
//Created a table of buttons. Each button has 3 textures: empty_button, x_button and o_button
//Textures will change after the players click of the buttons
//Used logic from "Game" class in order to verify the game state

const size_t TABLE_WIDTH = 3;
const size_t TABLE_HEIGHT = 3;
const size_t BUTTON_WIDTH = 150;
const size_t BUTTON_HEIGHT = 150;
const size_t BUTTON_SPACING = 10;
const size_t BOARD_PADDING = 100;
const size_t BOARD_WIDTH = TABLE_WIDTH * (BUTTON_WIDTH + BUTTON_SPACING) - BUTTON_SPACING + BOARD_PADDING * 2;
const size_t BOARD_HEIGHT = TABLE_HEIGHT * (BUTTON_HEIGHT + BUTTON_SPACING) - BUTTON_SPACING + BOARD_PADDING * 2;
const size_t LINE_THICKNESS = 10;

sf::RenderWindow window(sf::VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Tic Tac Toe");

class UI {


public:

    sf::RectangleShape buttons[TABLE_HEIGHT][TABLE_WIDTH];
    sf::Texture buttonTextures[3];

    void gameBoard();

    void playGame();

    void displayLabel();
    Game game;
};


#endif //X_0_UI_H
