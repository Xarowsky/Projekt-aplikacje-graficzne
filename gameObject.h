#pragma once
#include <SFML/Graphics.hpp>
#define OBJECTY this->objectSprite.getPosition().y
#define OBJECTX this->objectSprite.getPosition().x


class gameObject
{
public:

	sf::Sprite objectSprite;

	gameObject(sf::Texture objectTexture);

	bool detectCollision(gameObject obj1, gameObject obj2);
	float borderYAxisCollision(float screenHeight);
	float borderXAxisCollision(float screenWidth);
	void moveObject(float x, float y);
};