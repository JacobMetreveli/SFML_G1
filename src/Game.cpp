#include "../Headers/Game.h"

//Private functions
void Game::initVariables() {
    this->window = nullptr;
}

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 480), "Game 1", sf::Style::Titlebar | sf::Style::Close);
}

// Constructors and Destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

// Accessors
const bool Game::running() const {
    return this->window->isOpen();
}

// Functions
void Game::pollEvents() {
    // Event polling
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            default:
                break;
        }
    }
}


void Game::update() {
    this->pollEvents();
}

void Game::render() {
    this->window->clear(sf::Color::Red);

    // Draw game objects
    this->window->display();
}