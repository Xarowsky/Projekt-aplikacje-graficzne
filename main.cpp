#pragma once
#include "game.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"



int WinMain()
{
    int screenHeight = 480;
    int screenWidth = 640;
    sf::RenderWindow window;
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("assets/louda.wav"))
        return -1;
    Sound sound;
    sound.setBuffer(buffer);
    sound.play();

    window.setFramerateLimit(144);
 
    game newGame = game();

    while (window.isOpen())
    {
        newGame.loop();
    }

    return 0;
}