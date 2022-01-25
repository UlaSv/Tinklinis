#pragma once

#include "Defines.h"

struct Player
{
	float x, y; 
};

struct Net
{
	float StartY() { return y; }

	float EndY() { return y + NET_HEIGHT; }

	float TopX() { return x; }

	float BottomX() { return x + NET_WIDTH; }

	float x, y; 
};

struct Ball
{
	float BallStartY() { return y - 70;}

	float BallEndY() { return y + 70; }

	float BallX() { return x - 50; }

	float BallX2() { return x + 50; }

	float x, y;
};