#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Logic/Headers/Game.h"

const size_t TABLE_WIDTH = 3;
const size_t TABLE_HEIGHT = 3;
const size_t BUTTON_WIDTH = 150;
const size_t BUTTON_HEIGHT = 150;
const size_t BUTTON_SPACING = 10;
const size_t BOARD_PADDING = 100;
const size_t BOARD_WIDTH = TABLE_WIDTH * (BUTTON_WIDTH + BUTTON_SPACING) - BUTTON_SPACING + BOARD_PADDING * 2;
const size_t BOARD_HEIGHT = TABLE_HEIGHT * (BUTTON_HEIGHT + BUTTON_SPACING) - BUTTON_SPACING + BOARD_PADDING * 2;
const size_t LINE_THICKNESS = 10;

int main()
{
    Game game('X','O');
    game.start();
    game.setIsPlayerTurn(true);

    sf::RenderWindow window(sf::VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "Tic Tac Toe");

    // Set the window position to the center of the screen
    sf::Vector2i screenCenter(sf::VideoMode::getDesktopMode().width / 2,
                              sf::VideoMode::getDesktopMode().height / 2);
    sf::Vector2i windowPosition(screenCenter - sf::Vector2i(window.getSize().x / 2,
                                                            window.getSize().y / 2));
    window.setPosition(windowPosition);

    sf::RectangleShape buttons[TABLE_HEIGHT][TABLE_WIDTH];
    sf::Texture buttonTextures[3];

    // Create an array of buttons
    buttons[TABLE_HEIGHT][TABLE_WIDTH];

    buttonTextures[3];
    buttonTextures[0].loadFromFile("assets/button.png"); // texture for empty button
    buttonTextures[1].loadFromFile("assets/x_button.png"); // texture for X button
    buttonTextures[2].loadFromFile("assets/0_button.png"); // texture for 0 button

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

    while (window.isOpen()) {

        if(game.isPlayerTurn() == false && game.isGameActive() == true)
        {
            std::pair<int,int> pozitie = game.getComputer()->makeMove(game.getBoard());
            buttons[pozitie.first][pozitie.second].setTexture(&buttonTextures[2]);
            game.getBoard()->placeSign(pozitie.first,pozitie.second, '0');
            game.setIsPlayerTurn(true);
            int rezultat = game.checkWinner();
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        // Check if a button was clicked
                        for (int i = 0; i < TABLE_HEIGHT; i++) {
                            for (int j = 0; j < TABLE_WIDTH; j++) {
                                if (buttons[i][j].getGlobalBounds().contains(
                                        event.mouseButton.x, event.mouseButton.y)) {
                                    if(game.isPlayerTurn() == true && game.isGameActive() == true)
                                    {
                                        buttons[i][j].setTexture(&buttonTextures[1]);
                                        game.getBoard()->placeSign(i,j,'X');
                                        game.setIsPlayerTurn(false);
                                        int rezultat = game.checkWinner();
                                    }
                                    //used for 2 player game
//                                    if (xTurn == false && board[i][j] == -1)
//                                    {
//                                        buttons[i][j].setTexture(&buttonTextures[2]);
//                                        board[i][j] = 1;
//                                        xTurn = true;
//                                    }
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

        //Display the winner or DRAW
        if(game.checkWinner()!=-1 && game.isGameActive() == false){
            sf::Text text;
            sf::Font font;
            font.loadFromFile("assets/fonts/BAHNSCHRIFT.TTF");
            text.setFont(font);
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Red);
            switch(game.checkWinner()){
                case 0:{
                    text.setString("0 wins");
                    break;
                }
                case 1:{
                    text.setString("X wins");
                    break;
                }
                case 2:{
                    text.setString("DRAW");
                    break;
                }
            }

            window.draw(text);
        }

        // Draw the buttons
        for (int i = 0; i < TABLE_HEIGHT; i++) {
            for (int j = 0; j < TABLE_WIDTH; j++) {
                window.draw(buttons[i][j]);
            }
        }

        window.display();
    }

    return 0;
}
