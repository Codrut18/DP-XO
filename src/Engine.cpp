#include "engine.hpp"

const sf::Time Engine::TimePerFrame = seconds(1.f/60.f);

Engine::Engine() {
    resolution = Vector2f(800, 600);
    window.create(VideoMode(resolution.x, resolution.y), "X&0", Style::Default);
    window.setFramerateLimit(FPS);

}

void Engine::run() {

    // Main loop - Runs until the window is closed
    while (window.isOpen()) {
        input();
        draw();
    }
}

void Engine::input() {
    Event event{};

    while (window.pollEvent(event)) {
        // Window closed
        if (event.type == Event::Closed) {
            window.close();
        }

        // Handle Keyboard Input
        if (event.type == Event::KeyPressed) {
            // Quit
            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                window.close();
            }
        }
    }
}

void Engine::draw() {
    window.clear(Color::Yellow);

    drawBoard();
    //drawOShape(100,100,10);
    drawXShape(300,200,80);

    window.display();
}

void Engine::drawBoard() {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    int tableX = (WINDOW_WIDTH - 300) / 2;
    int tableY = (WINDOW_HEIGHT - 300) / 2;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if ((row + col) % 2 == 0) {
                sf::RectangleShape square(sf::Vector2f(100, 100));
                square.setFillColor(sf::Color::White);
                square.setOutlineThickness(2);
                square.setOutlineColor(sf::Color::Black);
                square.setPosition(tableX + col * 100, tableY + row * 100);
                window.draw(square);
            } else {
                sf::RectangleShape square(sf::Vector2f(100, 100));
                square.setFillColor(sf::Color::White);
                square.setOutlineThickness(2);
                square.setOutlineColor(sf::Color::Black);
                square.setPosition(tableX + col * 100, tableY + row * 100);
                window.draw(square);
            }
        }
    }
}

void Engine::drawOShape(float x, float y, float size) {

    sf::CircleShape oShape(40);
    oShape.setScale(1,1.15);
    oShape.setOutlineColor(sf::Color::Red);
    oShape.setOutlineThickness(5);

    window.draw(oShape);
}

void Engine::drawXShape(float x, float y, float size) {
    sf::RectangleShape line1(sf::Vector2f(size, 5));
    line1.setFillColor(sf::Color::Red);
    line1.rotate(45);
    line1.setPosition(x - size / 2 + 3, y - size / 2 + 23);

    sf::RectangleShape line2(sf::Vector2f(size, 5));
    line2.setFillColor(sf::Color::Red);
    line2.rotate(-45);
    line2.setPosition(x - size / 2, y + size / 2);

    window.draw(line1);
    window.draw(line2);
}


