#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "textures.h"
#include "gameObject.h"
#include "player.h"


class game
{
private:
	sf::RenderWindow *window;
	textures textureBank;
	std::list<gameObject> gameObjectBank;
	player *gamePlayer;
	gameObject *background;
	int screenHeight;
	int screenWidth;
//	virtual ~game();
public:
	game();
	void loop();
	void initWindow();
	void playerInit();
	void updateControls();
	void windowRefresh();
	void windowCtl();
	void initBackgroud();
};
