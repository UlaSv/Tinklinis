#pragma once

#ifndef Utils_H
#define Utils_H

#include "GameObjects.h"

namespace nmUtils
{
	bool IsBetween(float val, float rangeB, float rangeE);
	bool InOnNet(Ball& ball, Net& net);
	bool InOnNet2(Ball& ball, Net& net);
	void UpdatePositions(Player1& player1, Player2& player2, Net& net, Ball& ball, int& stepX, int& stepY);
	void Collision(Player1& player1, Player2& player2, Ball& ball, int& stepX, int& stepY);
	void Score(Ball& ball, Net& net, int& score1, int& score2);
}
#endif