#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#include "PrimitiveRenderer.h"

class GUI
{
private:
	sf::Font menu_font;
	sf::Font game_over_font;
	sf::Text game_over_text;
	sf::Text pointText;
	sf::Text hpText;
	float hp;
	int points;

public:

	GUI();

	void initGUI(sf::RenderWindow* window);
	void renderGUI(sf::RenderWindow *win);
	void updateGUI();

	void hit(float damage);
	float getHp();
	float getPoints();
};

