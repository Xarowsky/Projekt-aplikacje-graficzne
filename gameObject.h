#pragma once
#include <SFML/Graphics.hpp>
#define OBJECTY this->objectSprite.getPosition().y
#define OBJECTX this->objectSprite.getPosition().x

/**@brief
*Bazowa klasa obiektow gry
* 
****************************/
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

	/**@brief
	*metoda wyswietlajaca obiekt
	*/
	void render(sf::RenderTarget& target);
	/**@brief
	*metoda wykrywajaca kolizje
	*/
	bool detectCollision(gameObject obj1, gameObject obj2);
	/**@brief
	*metoda przemieszczajaca obiekt
	*/
	void moveObject(float x, float y);
	void setType();
};