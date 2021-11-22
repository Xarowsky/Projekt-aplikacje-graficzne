#pragma once
#include <SFML/Graphics.hpp>

class textures
{
private:
	sf::Texture playerPlane;
	sf::Texture background;
	sf::Texture playerProjectile;
	sf::Texture bulletTexture;

public:
		textures();
		sf::Texture *getPlayerTexture();
		sf::Texture *getBackgroundTexture();
		sf::Texture *getPlayerProjectile();
		sf::Texture *getBulletTexture();
};

