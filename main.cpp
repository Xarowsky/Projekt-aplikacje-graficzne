#pragma once
#include "game.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"


int WinMain()
{
    int screenHeight = 480;
    int screenWidth = 640;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Kapitan Bomba", sf::Style::Close);
    Point2D point(sf::Vector2f(100.f, 100.f), sf::Color::Red);

    window.setFramerateLimit(144);
 
    //game newGame = game();

    while (window.isOpen())
    {
        //newGame.loop();
        window.clear();
        window.draw(point);
        window.display();
    }

    return 0;
}