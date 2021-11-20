#pragma once
#include <SFML/Graphics.hpp>
#include "game.h"


int WinMain()
{
    int screenHeight = 480;
    int screenWidth = 640;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");

    window.setFramerateLimit(60);
 
    game newGame = game(screenHeight, screenWidth, &window);

    while (window.isOpen())
    {
        newGame.loop();
    }

    return 0;
}