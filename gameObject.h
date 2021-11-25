#pragma once
#include <SFML/Graphics.hpp>
#define OBJECTY this->objectSprite.getPosition().y
#define OBJECTX this->objectSprite.getPosition().x


class gameObject
{
public:
	std::string type;
	sf::Texture objTexture;
	sf::Sprite objectSprite;
	float xAxisCorrection = 0;
	float yAxisCorrection = 0;

	gameObject();
	gameObject(sf::Texture *objectTexture);
	~gameObject();

	void render(sf::RenderTarget& target);
	bool detectCollision(gameObject obj1, gameObject obj2);
	void moveObject(float x, float y);
	void setType();
};