#include <SFML/Graphics.hpp>

int WinMain()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    sf::RectangleShape shape;
    sf::Texture plane_texture;
    sf::Sprite plane_sprite;


    shape.setSize(sf::Vector2f(20, 20));
    window.setFramerateLimit(60);
    shape.setFillColor(sf::Color::Green);
    if (!plane_texture.loadFromFile("assets/plane_sprites.png"))
        return 404;

    plane_sprite.setTexture(plane_texture, true);

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
            plane_sprite.move(-10, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            plane_sprite.move(10, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            plane_sprite.move(0.f, -10);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            plane_sprite.move(0.f, 10);

        window.clear(sf::Color::Green);
        window.draw(plane_sprite);
        window.display();
    }

    return 0;
}