#pragma once
#include <SFML/Graphics.hpp>

class textures
{
private:
	sf::Texture playerPlane;
	sf::Texture background;

public:
		textures();
		sf::Texture *getPlayerTexture();
		sf::Texture *getBackgroundTexture();
};

