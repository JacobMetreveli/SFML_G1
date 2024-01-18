#include "../Headers/Game.h"


//Private functions
void Game::initVariables() {
    this->window = nullptr;

    // Game logic
    this->endGame = false;
    this->points = 0;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 10;
    this->mouseHeld = false;
    this->health = 100;
}


void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 480), "Game 1", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}


void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
}


// Constructors and Destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}


Game::~Game() {
    delete this->window;
}


// Accessors
const bool Game::running() const {
    return this->window->isOpen();
}


const bool Game::getEndGame() const {
    return this->endGame;
}


// Functions
void Game::spawnEnemy() {
    /*
        Spawns enemies and sets their colors and positions.
        -Sets a random position
        -Sets a random color.
        -Adds enemy to the vector.
    */
   
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );

    this->enemy.setFillColor(
        sf::Color::Green
    );

    // Spawn the enemy
    this->enemies.push_back(this->enemy);
}


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


void Game::updateMousePositions() {
    /*
        Updates the mouse positions:
            Mouse position relative to window (Vector2i)
    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}


void Game::updateEnemies() {
    // Updating the timer for enemy spawning
    if (this->enemies.size() < this->maxEnemies) {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            // Spawn the enemy and reset the timer
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        } else {
            this->enemySpawnTimer += 1.f;
        }
    }
    
    // Moving and updating the enemies
    for (int i = 0; i < this->enemies.size(); i++) {
        enemies[i].move(0.f, 5.f);    

        // If the enemy is past the bottom of the screen 
        if (this->enemies[i].getPosition().y > this->window->getSize().y) {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 10;
            std::cout << "Health: " << this->health << std::endl;
        }
    }

    // Check if clicked upon
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->mouseHeld == false) {
            this->mouseHeld = true;
            bool deleted = false;
            for (size_t i = 0; i < this->enemies.size() && deleted == false; i++) {
                if (enemies[i].getGlobalBounds().contains(this->mousePosView)) {
                    deleted = true;
                    this->enemies.erase(this->enemies.begin() + i);

                    // Gain points
                    this->points++;
                    std::cout << "Points: " << this->points << std::endl;
                }
            }
        }
    } else {
        this->mouseHeld = false;
    }
}


void Game::update() {
    this->pollEvents();

    if (!this->endGame) {
        this->updateMousePositions();

        this->updateEnemies();
    }

    // Endgame condition
    if (this->health <= 0) 
        this->endGame = true;
}


void Game::renderEnemies() {
    // Rendering all the enemies
    for (auto &e : this->enemies) {
        this->window->draw(e);
    }
}


void Game::render() {
    this->window->clear();

    // Draw game objects
    this->renderEnemies();

    this->window->display();
}