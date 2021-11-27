#pragma once
#include"gameObject.h"
#define PLAYER_SPEED 10

/**@brief
*Klasa gracza
*******************************/
class player :
    public gameObject
{
public:

    player();
    player(sf::Texture *objectTexture, sf::RenderWindow *win);

    /**@brief
    *Przemieszczenie gracza
    */
    void playerMove(const float dirX, const float dirY, sf::RenderWindow *window);
    /**@brief
    *kolizja z granicami ekranu
    */
    void worldCollision(sf::RenderWindow *window);
    void setType();
};

