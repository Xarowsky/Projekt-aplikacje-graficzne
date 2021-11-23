#pragma once
#include "gameObject.h"


class projectile
	:public gameObject
{
public:
	projectile();
	projectile(sf::Texture* objectTexture, sf::RenderWindow* win, float x, float y);
	void update();
	void setType();
};
