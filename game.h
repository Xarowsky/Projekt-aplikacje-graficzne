#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "textures.h"
#include "gameObject.h"
#include "player.h"
#include "projectile.h"
#include <list>
#include <iostream>
#include <sstream>


class game
{
private:
	sf::RenderWindow *window;
	textures textureBank;
	std::list<gameObject> gameObjectBank;
	player *gamePlayer;
	projectile *newProjectile;
	gameObject *background;
	sf::Font font;
	sf::Text pointText;
	sf::Text hpText;
	int screenHeight;
	int screenWidth;
	int points;
//	virtual ~game();
public:
	game();
	void loop();
	void initWindow();
	void initGUI();
	void renderGUI();
	void initBullets();
	void updateBullets();
	void renderBullets();
	void playerInit();
	void updateControls();
	void windowRefresh();
	void windowCtl();
	void initBackgroud();
};
