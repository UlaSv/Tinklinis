#include <SFML/Graphics.hpp>
#include <cmath>

#include "Objects.h"
#include "Utils.h"
#include "GameObjects.h"

using namespace std;

void UpdatePositions(Player1& player1, Player2& player2, Net& net, Ball& ball, int& stepX, int& stepY)
{
	const int dx = 5;
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
		stepX = 7;
	if (nmUtils::InOnNet2(ball, net))
		stepX = -7;

	if (ball.GetX() > WINDOW_WIDTH - BALL_WIDTH + 20)
		stepX = -7;
	if (ball.GetY() > WINDOW_HEIGHT - BALL_HEIGHT)
		stepY = -7;
	if (ball.GetX() < 80)
		stepX = 7;
	if (ball.GetY() < 80)
		stepY = 7;
}
void Collision(Player1 player1, Player2 player2, Ball ball, int& stepX, int& stepY)
{
	int xd, yd, distance, ballRadius, playerRadius;
	int xd_2, yd_2, distance2, player2Radius;
	const int x1 = ball.GetX();
	const int y1 = ball.GetY();
	const int x2 = player1.GetX();
	const int y2 = player1.GetY();
	const int x2_2 = player2.GetX();
	const int y2_2 = player2.GetY();
	ballRadius = ball.GetRadius();
	playerRadius = player1.GetRadius();
	player2Radius = player2.GetRadius();

	xd = x2 - x1;
	yd = y2 - y1;

	xd_2 = x2_2 - x1;
	yd_2 = y2_2 - y1;

	distance = sqrt((xd * xd) + (yd * yd));
	distance2 = sqrt((xd_2 * xd_2) + (yd_2 * yd_2));

	if (distance < (playerRadius + ballRadius))
	{
		stepX = rand() % 3 + 1 * 7;
		stepY = rand() % 3 - 1 * 7;
	}

	if (distance2 < (player2Radius + ballRadius))
	{
		stepX = rand() % 3 + 1 * -7;
		stepY = rand() % 3 - 1 * 7;
	}
}
void Score(Ball ball, Net net, int& score1, int& score2) 
{
	if (ball.GetY() > WINDOW_HEIGHT - 100 && ball.GetX() < net.GetX())
		score2++;
	if (ball.GetY() > WINDOW_HEIGHT - 100 && ball.GetX() > net.GetX())
		score1++;
}

int main()
{
	sf::RenderWindow app(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tenisas");
	app.setFramerateLimit(60);

	sf::Texture tBackground;
	tBackground.loadFromFile("Resources/background.png");
	sf::Sprite sprBackground(tBackground);

	Text tekstas;
	Contour remas;
	Player1 player1(WINDOW_WIDTH / 6, GROUND_Y);
	Player2 player2(WINDOW_WIDTH / 6 + WINDOW_WIDTH / 2, GROUND_Y);
	Net net(WINDOW_WIDTH / 2 - 20, GROUND_Y - 220);
	Ball ball(WINDOW_WIDTH / 6, GROUND_Y - 100);

	GameObject* pPlayer1 = dynamic_cast<Player1*>(&player1);
	GameObject* pPlayer2 = dynamic_cast<Player2*>(&player2);
	GameObject* pNet = dynamic_cast<Net*>(&net);
	GameObject* pBall = dynamic_cast<Ball*>(&ball);

	int score1 = 0, score2=0;
	int stepX = 7;
	int stepY = 7;

	while (app.isOpen())
	{
		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
		}

		UpdatePositions(player1, player2, net, ball, stepX, stepY);
		Collision(player1, player2, ball, stepX, stepY);
		Score(ball, net, score1, score2);
		
		app.draw(sprBackground);
		
		tekstas.PrintText(app, score1, score2);
		remas.DrawContour(app);
		
		pPlayer1->DrawObject(app);
		pPlayer2->DrawObject(app);
		pNet->DrawObject(app);
		pBall->DrawObject(app);

		app.display();
	}
	return 0;
}
