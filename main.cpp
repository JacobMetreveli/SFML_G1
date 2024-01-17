#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


int main() {
    // Window
    sf::Window window(sf::VideoMode(640, 480), "My first game", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    // Game loop
    while(window.isOpen()) {
        // Event polling
        while(window.pollEvent(ev)) {
            switch (ev.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                
            }
        }
    }

    return 0;
}