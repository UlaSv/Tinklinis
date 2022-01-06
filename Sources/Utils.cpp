
#include "Utils.h"
#include "Objects.h"

bool nmUtils::IsBetween(float val, float rangeB, float rangeE)
{
	return val > rangeB && val < rangeE;
}

bool nmUtils::InOnNet(Ball& ball, Net& net)
{
	const bool betweenY = IsBetween(ball.BallStartY(), net.StartY(), ball.BallEndY()) ||
		IsBetween(ball.BallEndY(), net.StartY(), net.EndY());

	const bool betweenX = IsBetween(ball.BallX(), net.TopX(), net.BottomX());

	return betweenX && betweenY;
}
