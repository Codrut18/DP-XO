#include <SFML/Graphics.hpp>
#include <iostream>

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

    short board[3][3] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    bool xTurn = true;

    while (window.isOpen()) {

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
                                    if(board[i][j] == -1 && xTurn == true)
                                    {
                                        buttons[i][j].setTexture(&buttonTextures[1]);
                                        board[i][j] = 1;
                                        xTurn = false;
                                    }
                                    if (xTurn == false && board[i][j] == -1)
                                    {
                                        buttons[i][j].setTexture(&buttonTextures[2]);
                                        board[i][j] = 1;
                                        xTurn = true;
                                    }
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

    return 0;
}
