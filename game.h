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

/**@brief
*Klasa zwierajaca glowna petle, jej skladowe oraz logike
*****************************************/
class game
{
private:
	sf::Color ColArr[5] = { sf::Color::Red, sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White};
	sf::RenderWindow *window;
	textures textureBank;
	Menu gameMenu;
	std::vector<enemies*> enemies_list;
	std::vector<gameObject*> ProjectileBank;
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
	/**@brief
	*konstruktor gry
	*/
	game();
	/**@brief
	*glowna petla gry
	*/
	void loop();
	/**@brief
	*metoda inicjalizujaca okno
	*/
	void initWindow();
	/**@brief
	*metoda ladujaca dzwiek
	*/
	void initSound();
	/**@brief
	*metoda inicjalizujaca obiekt gracza
	*/
	void playerInit();
	/**@brief
	*czesc logiki odpowiedzialna za tworzenie przeciwnikow
	*/
	void spawnEnemies();
	/**@brief
	*metoda aktualizujaca stan przeciwnikow
	*/
	void updateEnemies();
	/**@brief
	*metoda renderujaca przeciwnikow
	*/
	void renderEnemies();
	/**@brief
	*logika sterowania
	*/
	void updateControls();
	/**@brief
	*metoda odswiezajaca ekran
	*/
	void windowRefresh();
	/**@brief
	*metoda sterujaca ekranem oraz menu glownym
	*/
	void windowCtl();
	/**@brief
	*metoda sprawdzajaca kolizje miedzy spritem a kolem
	*/
	bool isColliding(Sprite s1, CircleShape s2);
	/**@brief
	*metoda inicjalizujaca tlo ekranu
	*/
	void initBackgroud();
	/**@brief
	*metoda zmieniajaca stan pociskow
	*/
	void updateObjects();
	/**@brief
	*metoda renderujaca pociski
	*/
	void renderObjects();
	/**@brief
	*metoda tworzaca nowe pociski
	*/
	void shoot();
	/**@brief
	*metoda dekonstruujaca obiekty znajdujace sie poza ekranem
	*/
	void cleanupObjects();

	bool gameover = false;
};
