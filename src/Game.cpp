#include "Game.h"

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

// Functions
void Game::update() {

}

void Game::render() {

}