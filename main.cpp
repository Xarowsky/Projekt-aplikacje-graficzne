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

    window.setFramerateLimit(144);
 
    game newGame = game();

    while (window.isOpen())
    {
        newGame.loop();
        //window.clear();
        //renderer.drawPoint(&window, &point);
        //renderer.drawLine(&window, &line);
        //renderer.drawPolygons(&window, 50.f, 3, sf::Color::Blue, sf::Vector2f(200.f, 100.f));
        //window.display();
    }

    return 0;
}