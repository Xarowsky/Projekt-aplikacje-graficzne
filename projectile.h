#pragma once
#include "gameObject.h"

class projectile
	:gameObject
{
	projectile();
	projectile(sf::Texture* objectTexture, sf::RenderWindow* win);
	void update();
};
