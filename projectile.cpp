#include "projectile.h"


projectile::projectile()
{

}


projectile::projectile(sf::Texture* objectTexture, sf::RenderWindow* win, float x, float y)
{
	type = "projectile";
	this->objTexture = sf::Texture(*objectTexture);
	this->objectSprite = sf::Sprite();
	this->objectSprite.setTexture(objTexture, true);
	this->objectSprite.setRotation(90.f);
	this->objectSprite.setOrigin(objectSprite.getGlobalBounds().width / 2 - objectTexture->getSize().x / 2, objectSprite.getGlobalBounds().height / 2 + objectTexture->getSize().y);
	this->objectSprite.setScale(0.2f, 0.2f);
	this->objectSprite.setPosition(x, y);
}

void projectile::update()
{
	this->objectSprite.move(15.f,0.f);
}
