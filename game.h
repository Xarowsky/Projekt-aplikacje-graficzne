#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "textures.h"
#include "gameObject.h"
#include "player.h"
#include "projectile.h"
#include "PrimitiveRenderer.h"
#include <list>
#include <iostream>
#include <sstream>
#include "enemies.h"


class game
{
private:
	sf::RenderWindow *window;
	textures textureBank;
	std::vector<enemies*> enemies_list;
	std::vector<gameObject*> gameObjectBank;
	player *gamePlayer;
	float time;
	float time2;
	enemies* enemy = new enemies();
	SoundBuffer buffer;
	Sound sound;
	float timer = 0, delay = 0.2, timer2 = 0, delay2 = 5;
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
	void initSound();
	void playerInit();
	void spawnEnemies();
	void updateEnemies();
	void renderEnemies();
	void updateControls();
	void windowRefresh();
	void windowCtl();
	bool isColliding(Sprite s1, CircleShape s2);
	void initBackgroud();
	void updateObjects();
	void renderObjects();
	void shoot();
	
};
