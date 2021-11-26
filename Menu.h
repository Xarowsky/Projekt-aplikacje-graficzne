#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
private:
	int selectedItemIndex;
	int volume;
	sf::Font menu_font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text volumeLevel;
	sf::Texture menuTexture;
	sf::Sprite menuSprite;
public:
	Menu();
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	float MoveLeft(float currentVolume);
	float MoveRight(float currentVolume);
	void updateVolume(int currentVolume);
	void inGameVolume(int currentVolume, sf::RenderWindow *window);
	int GetPressedItem() { return selectedItemIndex; }
};

