#include <iostream>
#include "../include/Game.h"


int main() {
    // Window
    sf::RenderWindow window(sf::VideoMode(800, 600), "G1", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    // Game loop
    while(window.isOpen()) {
        // Event polling
        while(window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape)
                        window.close();
                    break;
                default:
                    break;
            }
        }

        // Update


        // Render
        window.clear(sf::Color::Red); // Clear old frame

            // Draw the frame
        window.display(); // Tell app that window is done drawing
    }

    return 0;
}