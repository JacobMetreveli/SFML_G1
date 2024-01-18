#pragma once

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

/*
    Class that acts as the game engine.
    Wrapper class.
*/
class Game {
    private:
        // Variables
        // Window
        sf::RenderWindow* window;
        sf::Event ev;

        //Mouse positions
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        //Game logic
        bool endGame;
        unsigned points;
        int health;
        float enemySpawnTimer;
        float enemySpawnTimerMax;
        int maxEnemies;
        bool mouseHeld;

        // Game objects
        std::vector<sf::RectangleShape> enemies;
        sf::RectangleShape enemy;

        // Functions
        void initVariables();
        void initWindow();
        void initEnemies();

    public:
        // Constructors && Destructors
        Game();
        virtual ~Game();

        // Accessors
        const bool running() const;
        const bool getEndGame() const;

        // Functions
        void spawnEnemy();
        
        void pollEvents();
        void updateMousePositions();
        void updateEnemies();
        void update();

        void renderEnemies();
        void render();
};