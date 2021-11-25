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
#include "GUI.h"


class game
{
private:
	sf::Color ColArr[5] = { sf::Color::Red, sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White};
	sf::RenderWindow *window;
	textures textureBank;
	std::vector<enemies*> enemies_list;
	std::vector<gameObject*> gameObjectBank;
	player *gamePlayer;
	float time;
	float time2;
	SoundBuffer buffer;
	SoundBuffer death_buffer;
	SoundBuffer oof;
	Sound sound;
	Sound death_sound;
	Sound gotHit;
	float timer = 0, delay = 0.2, timer2 = 0, delay2 = 5;
	projectile *newProjectile;
	gameObject *background;

	int screenHeight;
	int screenWidth;

	GUI gamegui;

//	virtual ~game();
public:
	game();
	void loop();
	void initWindow();
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
	bool gameover = false;
};
