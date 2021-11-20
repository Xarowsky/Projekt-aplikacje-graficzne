#pragma once
#include <list>
#include "textures.h"
#include "gameObject.h"
#include "player.h"

class game
{
private:
	sf::RenderWindow *window;
	textures textureBank;
	std::list<gameObject> gameObjectBank;
	player gamePlayer;
	int screenHeight;
	int screenWidth;
public:
	game();
	game(int scrHeight, int scrWidth, sf::RenderWindow *win);
	void loop();
	void windowRefresh();
	void windowCtl();
};
