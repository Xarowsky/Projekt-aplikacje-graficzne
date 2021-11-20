#pragma once
#include"gameObject.h"
#define PLAYER_SPEED 10


class player :
    public gameObject
{
public:

    player();
    player(sf::Texture *objectTexture);

    void playerControls(int screenWidth, int screenHeight);
};

