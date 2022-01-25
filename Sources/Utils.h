#pragma once

struct Player;
struct Net;
struct Ball;

namespace nmUtils
{
	bool IsBetween(float val, float rangeB, float rangeE);
	bool InOnNet(Ball& ball, Net& net);
	bool InOnNet2(Ball& ball, Net& net);
}
