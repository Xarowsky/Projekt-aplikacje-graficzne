#pragma once
#include"gameObject.h"
#define PLAYER_SPEED 10


class player :
    public gameObject
{
public:
    int xAxisCorrection = 0;
    int yAxisCorrection = 0;

    void playerControls(int screenWidth, int screenHeight);
};

