#include "player.h"


player::player()
{

}


player::player(sf::Texture *objectTexture)
{
    this->objTexture = sf::Texture(*objectTexture);
    this->objectSprite = sf::Sprite();
    this->objectSprite.setTexture(objTexture, true);
}


void player::playerMove(const float dirX, const float dirY, sf::RenderWindow *window)
{
    this->objectSprite.move(PLAYER_SPEED * dirX, PLAYER_SPEED * dirY);
	this->worldCollision(window);
}


void player::worldCollision(sf::RenderWindow *window)
{
	if (this->objectSprite.getGlobalBounds().left < 0.f)
	{
		this->objectSprite.setPosition(0.f, this->objectSprite.getGlobalBounds().top);
	}
	else if (this->objectSprite.getGlobalBounds().left + this->objectSprite.getGlobalBounds().width >= window->getSize().x)
	{
		this->objectSprite.setPosition(window->getSize().x - this->objectSprite.getGlobalBounds().width, this->objectSprite.getGlobalBounds().top);
	}
	if (this->objectSprite.getGlobalBounds().top < 0.f)
	{
		this->objectSprite.setPosition(this->objectSprite.getGlobalBounds().left, 0.f);
	}
	else if (this->objectSprite.getGlobalBounds().top + this->objectSprite.getGlobalBounds().height >= window->getSize().y)
	{
		this->objectSprite.setPosition(this->objectSprite.getGlobalBounds().left, window->getSize().y - this->objectSprite.getGlobalBounds().height);
	}
}
