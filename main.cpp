#pragma once
#include "game.h"


int WinMain()
{
    int screenHeight = 480;
    int screenWidth = 640;
    sf::RenderWindow window;

    window.setFramerateLimit(144);
 
    game newGame = game();

    while (window.isOpen())
    {
        newGame.loop();
    }

    return 0;
}