#pragma once
#include"gameObject.h"
#define PLAYER_SPEED 10


class player :
    public gameObject
{
public:

    player();
    player(sf::Texture *objectTexture);

    void playerMove(const float dirX, const float dirY, sf::RenderWindow *window);
    void render(sf::RenderTarget& target);
    void worldCollision(sf::RenderWindow *window);
};

