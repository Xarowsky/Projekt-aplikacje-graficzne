#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class gameTextures
{
public:
	std::map<sf::Texture, std::string> textureMap;
	
	gameTextures();

	int loadTexture(std::string path,std::string textureName);
	sf::Texture getTexture(std::string texturename);
	bool emptyTextureBank();
};