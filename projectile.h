#pragma once
#include "gameObject.h"

class projectile
	:public gameObject
{
public:
	projectile();
	projectile(sf::Texture* objectTexture, sf::RenderWindow* win);
	void update();
};
