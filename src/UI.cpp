#include <iostream>
#include "UI.h"

void UI::playGame() {
    sf::RenderWindow window(sf::VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Tic Tac Toe");

    // Set the window position to the center of the screen
    sf::Vector2i screenCenter(sf::VideoMode::getDesktopMode().width / 2,
                              sf::VideoMode::getDesktopMode().height / 2);
    sf::Vector2i windowPosition(screenCenter - sf::Vector2i(window.getSize().x / 2,
                                                            window.getSize().y / 2));
    window.setPosition(windowPosition);

    gameBoard();

    game.gameActive = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left && game.gameActive == true) {
                        // Check if a button was clicked
                        for (int i = 0; i < TABLE_HEIGHT; i++) {
                            for (int j = 0; j < TABLE_WIDTH; j++) {
                                if (buttons[i][j].getGlobalBounds().contains(
                                        event.mouseButton.x, event.mouseButton.y)) {
                                    if(game.xTurn == true && game.board[i][j] == -1)
                                    {
                                        buttons[i][j].setTexture(&buttonTextures[1]);
                                        game.board[i][j] = game.xTurn;
                                        game.xTurn = false;
                                    }
                                    if (game.xTurn == false && game.board[i][j] == -1)
                                    {
                                        buttons[i][j].setTexture(&buttonTextures[2]);
                                        game.board[i][j] = game.xTurn;
                                        game.xTurn = true;
                                    }
                                    game.checkGameState();
                                    //std::cout << "Button (" << i << "," << j << ") clicked!\n";
                                }
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        window.clear(sf::Color::Yellow);

        // Draw the buttons
        for (int i = 0; i < TABLE_HEIGHT; i++) {
            for (int j = 0; j < TABLE_WIDTH; j++) {
                window.draw(buttons[i][j]);
            }
        }

        window.display();
    }

}

void UI::gameBoard() {
    // Create the game board
    for(int i = 0 ; i < TABLE_HEIGHT; i++)
        for(int j = 0; j < TABLE_WIDTH; j++)
            board[i][j] = 0;

    // Create an array of buttons
    buttons[TABLE_HEIGHT][TABLE_WIDTH];

    buttonTextures[3];
    buttonTextures[0].loadFromFile("../assets/button.png"); // texture for empty button
    buttonTextures[1].loadFromFile("../assets/x_button.png"); // texture for X button
    buttonTextures[2].loadFromFile("../assets/o_button.png"); // texture for 0 button

    for (int i = 0; i < TABLE_HEIGHT; i++) {
        for (int j = 0; j < TABLE_WIDTH; j++) {
            buttons[i][j].setSize(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
            buttons[i][j].setOutlineThickness(2);
            buttons[i][j].setOutlineColor(sf::Color::Black);
            buttons[i][j].setPosition(
                    j * (BUTTON_WIDTH + BUTTON_SPACING) + BUTTON_SPACING + BOARD_PADDING,
                    i * (BUTTON_HEIGHT + BUTTON_SPACING) + BUTTON_SPACING + BOARD_PADDING);
        }
    }
}

