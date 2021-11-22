#pragma once
#include "textures.h"


textures::textures()
{
	if (!playerPlane.loadFromFile("assets/plane_sprites.png"))
		exit(1);
	if (!background.loadFromFile("assets/galaxy.jpg"))
		exit(1);
}


sf::Texture *textures::getPlayerTexture()
{
	return &playerPlane;
}


sf::Texture *textures::getBackgroundTexture()
{
	return &background;
}