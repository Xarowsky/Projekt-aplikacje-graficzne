#include "player.h"


player::player()
{

}


player::player(sf::Texture *objectTexture, sf::RenderWindow *win)
{
    this->objTexture = sf::Texture(*objectTexture);
    this->objectSprite = sf::Sprite();
    this->objectSprite.setTexture(objTexture, true);
	this->objectSprite.setRotation(90.f);
	this->objectSprite.setOrigin(objectSprite.getGlobalBounds().width / 2, objectSprite.getGlobalBounds().height / 2);
	this->objectSprite.setPosition(((float)win->getSize().x/2), ((float)win->getSize().y/2));
}


void player::playerMove(const float dirX, const float dirY, sf::RenderWindow *window)
{
    this->objectSprite.move(PLAYER_SPEED * dirX, PLAYER_SPEED * dirY);
	this->worldCollision(window);
}


void player::worldCollision(sf::RenderWindow *window)
{
	if (this->objectSprite.getPosition().x < 0.f)
	{
		this->objectSprite.setPosition(0.f, this->objectSprite.getPosition().y);
	}
	else if (this->objectSprite.getPosition().x > window->getSize().x)
	{
		this->objectSprite.setPosition(window->getSize().x, this->objectSprite.getPosition().y);
	}
	else if (this->objectSprite.getPosition().y < 0.f)
	{
		this->objectSprite.setPosition(this->objectSprite.getPosition().x, 0.f);
	}
	else if (this->objectSprite.getPosition().y > window->getSize().y)
	{
		this->objectSprite.setPosition(this->objectSprite.getPosition().x, window->getSize().y);
	}
}

void player::setType()
{
	this->type = "player";
}
