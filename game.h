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
#include "Menu.h"


class game
{
private:
	sf::Color ColArr[5] = { sf::Color::Red, sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White};
	sf::RenderWindow *window;
	textures textureBank;
	Menu gameMenu;
	std::vector<enemies*> enemies_list;
	std::vector<gameObject*> gameObjectBank;
	player *gamePlayer;
	float time;
	float time2;
	SoundBuffer buffer;
	SoundBuffer death_buffer;
	SoundBuffer oof;
	sf::SoundBuffer mainBuffer;
	Sound mainSound;
	Sound sound;
	Sound death_sound;
	Sound gotHit;
	float timer = 0, delay = 0.2, timer2 = 0, delay2 = 3;
	projectile *newProjectile;
	gameObject *background;
	bool menuStates[5];
	bool isPressed;
	bool menuOff;
	int difficulty;
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
	void cleanupObjects();
	bool gameover = false;
};
