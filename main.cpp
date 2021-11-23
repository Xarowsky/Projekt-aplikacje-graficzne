#pragma once
#include "game.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"



int WinMain()
{
    int screenHeight = 480;
    int screenWidth = 640;
    PrimitiveRenderer renderer;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Kapitan Bomba", sf::Style::Close);
    Point2D point(sf::Vector2f(100.f, 100.f), sf::Color::Red);
    LineSegment line(sf::Vector2f(100.f, 100.f), sf::Vector2f(300.f, 300.f), sf::Color::Green);

    line.changePoints(line.getPointBegin(), sf::Vector2f(100.f, 300.f));

    window.setFramerateLimit(144);
 
    //game newGame = game();

    while (window.isOpen())
    {
        //newGame.loop();
        window.clear();
        renderer.drawPoint(&window, &point);
        renderer.drawLine(&window, &line);
        window.display();
    }

    return 0;
}