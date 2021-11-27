#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <iostream>
#define MAX_NUMBER_OF_ITEMS 2
/**@brief
*klasa glownego menu
* 
************************************/
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
	/**@brief
	*metoda rysujaca menu
	*/
	void draw(sf::RenderWindow& window);
	/**@brief
	*zmiana obecnie wybranej opcji menu
	*/
	void MoveUp();
	/**@brief
	*zmiana obecnie wybranej opcji menu
	*/
	void MoveDown();
	/**@brief
	*
	*/
	void updateVolume(int currentVolume);
	/**@brief
	*
	*/
	void inGameVolume(int currentVolume, sf::RenderWindow *window);
	/**@brief
	*getter zwracajacy wybrana opcje menu
	*/
	int GetPressedItem() { return selectedItemIndex; }
};

