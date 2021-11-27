#pragma once
#include <SFML/Graphics.hpp>
/**@brief
*Klasa zawierajaca oryginaly poszczegolnych tekstur
****************/
class textures
{
private:
	sf::Texture playerPlane;
	sf::Texture background;
	sf::Texture playerProjectile;
	sf::Texture bulletTexture;

public:
	textures();
	/**@brief
	*getter teksury gracza
	*/
	sf::Texture *getPlayerTexture();
	/**@brief
	*getter tektury tla
	*/
	sf::Texture *getBackgroundTexture();
	/**@brief
	*getter tekstury pocisku
	*/
	sf::Texture *getPlayerProjectile();
	//sf::Texture *getBulletTexture();
};

