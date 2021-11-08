#include <SFML/Graphics.hpp>


int WinMain()
{
    int screenHeight = 480;
    int screenWidth = 640;
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML works!");
    sf::RectangleShape shape;

    sf::Texture plane_texture;
    sf::Sprite plane_sprite;

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


        window.clear(sf::Color::Green);
        window.draw(plane_sprite);
        window.display();
    }

    return 0;
}