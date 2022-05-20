#include "Utils.h"

void nmUtils::UpdatePositions(Player& player1, Player& player2, Net& net, Ball& ball, int& stepX, int& stepY)
{
	const int dx = 10;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player1.XCoordinate(-dx);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player1.XCoordinate(dx);
	if (ball.GetX() >= player2.GetX() && ball.GetX() > net.GetX())
		player2.XCoordinate(dx);
	else if (ball.GetX() < player2.GetX() + BALL_WIDTH && ball.GetX() > net.GetX())
		player2.XCoordinate(-dx);

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

	if (ball.GetX() > WINDOW_WIDTH - BALL_WIDTH + 15)
		stepX = -dx;
	if (ball.GetY() > WINDOW_HEIGHT - BALL_HEIGHT + 20)
		stepY = -dx;
	if (ball.GetX() < 60)
		stepX = dx;
	if (ball.GetY() < 70)
		stepY = dx;
}

void nmUtils::Collision(Player& player1, Player& player2, Ball& ball, int& stepX, int& stepY)
{
	srand(time(NULL));
	if (ball.GetSprite().getGlobalBounds().intersects(player1.GetSprite().getGlobalBounds()))
	{
		stepX = (rand() % 8) * 2;
		stepY = (rand() % 8 + 5) * -2;
	}
	if (ball.GetSprite().getGlobalBounds().intersects(player2.GetSprite().getGlobalBounds()))
	{
		stepX = (rand() % 8 - 5) * 2;
		stepY = (rand() % 8 + 5) * -2;
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

	const bool betweenX = IsBetween(ball.BallX(), net.StartX(), net.EndX());

	return betweenX && betweenY;
}
bool nmUtils::InOnNet2(Ball& ball, Net& net)
{
	const bool betweenY = IsBetween(ball.BallStartY(), net.StartY(), ball.BallEndY()) ||
		IsBetween(ball.BallEndY(), net.StartY(), net.EndY());

	const bool betweenX = IsBetween(ball.BallX2(), net.StartX(), net.EndX());

	return betweenX && betweenY;
}
