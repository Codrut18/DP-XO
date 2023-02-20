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
    window.clear(Color::Black);

    window.display();
}