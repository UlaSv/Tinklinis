#include "Utils.h"

void nmUtils::UpdatePositions(Player1& player1, Player2& player2, Net& net, Ball& ball, int& stepX, int& stepY)
{
	const int dx = 7;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player1.XCoordinate(-dx);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player1.XCoordinate(dx);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player2.XCoordinate(-dx);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player2.XCoordinate(dx);

	const int stop = 10;
	if (player1.GetX() >= net.GetX() - 30)
		player1.XCoordinate(-stop);

	if (player1.GetX() < 70)
		player1.XCoordinate(stop);

	if (player2.GetX() <= net.GetX() + 60)
		player2.XCoordinate(stop);

	if (player2.GetX() >= WINDOW_WIDTH - 65)
		player2.XCoordinate(-stop);

	ball.XCoordinate(stepX);
	ball.YCoordinate(stepY);

	if (nmUtils::InOnNet(ball, net))
		stepX = dx;
	if (nmUtils::InOnNet2(ball, net))
		stepX = -dx;

	if (ball.GetX() > WINDOW_WIDTH - BALL_WIDTH + 20)
		stepX = -dx;
	if (ball.GetY() > WINDOW_HEIGHT - BALL_HEIGHT)
		stepY = -dx;
	if (ball.GetX() < 80)
		stepX = dx;
	if (ball.GetY() < 80)
		stepY = dx;
}

void nmUtils::Collision(Player1& player1, Player2& player2, Ball& ball, int& stepX, int& stepY)
{
	int xd[2], yd[2], distance[2], ballRadius, playerRadius[2];
	const int x1 = ball.GetX();
	const int y1 = ball.GetY();
	ballRadius = ball.GetRadius();
	playerRadius[0] = --player1;
	playerRadius[1] = --player2;
	xd[0] = player1 - x1;
	yd[0] = player1.GetY() - y1;
	xd[1] = player2 - x1;
	yd[1] = player2.GetY() - y1;

	for (int i = 0; i < 2; i++)
	{
		distance[i] = sqrt((xd[i] * xd[i]) + (yd[i] * yd[i]));
		if (distance[i] < (playerRadius[i] + ballRadius))
		{
			stepX = rand() % 3 + 1 * 7;
			stepY = rand() % 3 - 1 * 7;
		}
	}
}
void nmUtils::Score(Ball& ball, Net& net, int& score1, int& score2)
{
	if (ball.GetY() > WINDOW_HEIGHT - 100 && ball.GetX() < net.GetX())
		score2++;
	if (ball.GetY() > WINDOW_HEIGHT - 100 && ball.GetX() > net.GetX())
		score1++;
}

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
bool nmUtils::InOnNet2(Ball& ball, Net& net)
{
	const bool betweenY = IsBetween(ball.BallStartY(), net.StartY(), ball.BallEndY()) ||
		IsBetween(ball.BallEndY(), net.StartY(), net.EndY());

	const bool betweenX = IsBetween(ball.BallX2(), net.TopX(), net.BottomX());

	return betweenX && betweenY;
}
