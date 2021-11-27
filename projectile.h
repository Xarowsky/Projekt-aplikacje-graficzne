#pragma once
#include "gameObject.h"

/**@brief
* Klasa pocisku
* 
***********************/
class projectile
	:public gameObject
{
public:
	projectile();
	/**@brief
	*konstruktor
	*/
	projectile(sf::Texture* objectTexture, sf::RenderWindow* win, float x, float y);
	/**@brief
	*zmiana stanu pocisku
	*/
	void update();
	void setType();
};
