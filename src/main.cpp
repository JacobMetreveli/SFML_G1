#include <iostream>
#include "../Headers/Game.h"



int main() {
    // Init game engine
    Game game = Game();

    // Game loop
    while(game.running()) {
        // Update
        game.update();

        // Render
        game.render();
    }

    return 0;
}