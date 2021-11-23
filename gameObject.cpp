#include"gameObject.h"


gameObject::gameObject()
{

}


gameObject::gameObject(sf::Texture *objectTexture)
{
	this->objTexture = sf::Texture(*objectTexture);
	this->objectSprite = sf::Sprite();
	this->objectSprite.setTexture(objTexture, true);
}


void gameObject::render(sf::RenderTarget& target)
{
	target.draw(this->objectSprite);
}


bool gameObject::detectCollision(gameObject obj1, gameObject obj2)
{
	if (obj1.objectSprite.getGlobalBounds().intersects(obj2.objectSprite.getGlobalBounds()))
		return true;
	else
		return false;
}


void gameObject::moveObject(float x, float y)
{
	this->objectSprite.move(x, y);
}


void gameObject::setType()
{

}