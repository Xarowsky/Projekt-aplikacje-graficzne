#include "projectile.h"


projectile::projectile()
{
	
}


projectile::projectile(sf::Texture* objectTexture, sf::RenderWindow* win)
{
	this->objTexture = sf::Texture(*objectTexture);
	this->objectSprite = sf::Sprite();
	this->objectSprite.setTexture(objTexture, true);
	this->objectSprite.setRotation(90.f);
	this->objectSprite.setOrigin(objectSprite.getGlobalBounds().width / 2, objectSprite.getGlobalBounds().height / 2);
	this->objectSprite.setPosition(((float)win->getSize().x / 2), ((float)win->getSize().y / 2));
}