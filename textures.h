#pragma once
#include <SFML/Graphics.hpp>

class textures
{
private:
	sf::Texture playerPlane;

public:
		textures();
		sf::Texture *getPlayerTexture();
};

