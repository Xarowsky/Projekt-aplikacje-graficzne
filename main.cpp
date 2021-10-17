#include <SFML/Graphics.hpp>

int WinMain()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(20, 20));
    window.setFramerateLimit(60);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                break;
            }
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            shape.move(-10, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            shape.move(10, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            shape.move(0.f, -10);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            shape.move(0.f, 10);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}