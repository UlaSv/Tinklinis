#include <SFML/Graphics.hpp>
#include <format>
#include <cmath>

#include "Objects.h"
#include "Utils.h"
#include "Main.h"

using namespace sf;
using namespace std;

void UpdatePositions(Player& player, Player& player1, Net& net, Ball& ball)
{
	const float dx = 3.0f;
	const float dy = 10.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player.x -= dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player.x += dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player.y -= dy;
		if (player.y <= 450)
			player.y = GROUND_Y;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player1.x -= dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player1.x += dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player1.y -= dy;
		if (player1.y <= 450)
			player1.y = GROUND_Y;
	}

	if (player.x >= net.x - 95)
		player.x = net.x - 95;

	if (player.x < 0)
		player.x = 0;

	if (player1.x <= net.x + 10)
		player1.x = net.x + 10;

	if (player1.x >= WINDOW_WIDTH - 95)
		player1.x = WINDOW_WIDTH - 95;

	
}

int main()
{
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tenisas");
	app.setFramerateLimit(60);

	Texture tBackground, tPlayer1, tNet, tPlayer2, tBall;
	tBackground.loadFromFile("Resources/background.png");
	tPlayer1.loadFromFile("Resources/player.png");
	tPlayer2.loadFromFile("Resources/player1.png");
	tNet.loadFromFile("Resources/Net.png");
	tBall.loadFromFile("Resources/ball.png");

	Sprite sprBackground(tBackground);
	Sprite sprPlayer(tPlayer1);
	Sprite sprPlayer1(tPlayer2);
	Sprite sprNet(tNet);
	Sprite sprBall(tBall);

	Player player;
	player.x = WINDOW_WIDTH / 6;
	player.y = GROUND_Y;

	Player player1;
	player1.x = WINDOW_WIDTH / 6 + WINDOW_WIDTH / 2;
	player1.y = GROUND_Y;

	Net net;
	net.x = WINDOW_WIDTH / 2 - 10;
	net.y = GROUND_Y - 190;

	Ball ball;
	ball.x = WINDOW_WIDTH / 6;
	ball.y = GROUND_Y -100;

	float stepX = 5.0f;
	float stepY = 5.0f;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		UpdatePositions(player,player1, net, ball);

		ball.x += stepX;
		ball.y += stepY;

		if (sprBall.getPosition().x > WINDOW_WIDTH - BALL_WIDTH )
		{
			stepX = -5;
		}
		if (sprBall.getPosition().y > WINDOW_HEIGHT - BALL_HEIGHT )
		{
			stepY = -5;
		}
		if (sprBall.getPosition().x < 0)
		{
			stepX = 5;
		}
		if (sprBall.getPosition().y < 0)
		{
			stepY = 5;
		}

		float x1, y1, x2, y2, xd, yd, distance, ballRadius, playerRadius;
		x1 = sprBall.getPosition().x;
		y1 = sprBall.getPosition().y;
		x2 = sprPlayer.getPosition().x;
		y2 = sprPlayer.getPosition().y;
		ballRadius = 52;
		playerRadius = 53;

		xd = x2 - x1;
		yd = y2 - y1;

		distance = sqrt((xd * xd) + (yd * yd));

		if (distance < (playerRadius + ballRadius))
		{
			stepX = rand() % 3 + 1 * 5;
			stepY = rand() % 3 - 1 * 5 ;
		}
		float x1_2, y1_2, x2_2, y2_2, xd_2, yd_2, distance2, player1Radius;
		x1_2 = sprBall.getPosition().x;
		y1_2 = sprBall.getPosition().y;
		x2_2 = sprPlayer1.getPosition().x;
		y2_2 = sprPlayer1.getPosition().y;
		player1Radius = 53;

		xd_2 = x2_2 - x1_2;
		yd_2 = y2_2 - y1_2;

		distance2 = sqrt((xd_2 * xd_2) + (yd_2 * yd_2));

		if (distance2 < (player1Radius + ballRadius))
		{
			stepX = rand() % 3 + 1 * 5;
			stepY = rand() % 3 - 1 * 5;
		}
		
		app.draw(sprBackground);

		sprPlayer.setPosition(player.x, player.y);
		//sprPlayer.setOrigin(53, 53);
		app.draw(sprPlayer);
		sprPlayer1.setPosition(player1.x, player1.y);
		//sprPlayer.setOrigin(53, 53);
		app.draw(sprPlayer1);
		sprBall.setPosition(ball.x, ball.y);
		//sprBall.setOrigin(53,50);
		app.draw(sprBall);
		sprNet.setPosition(net.x, net.y);
		app.draw(sprNet);

		app.display();
	}

	return 0;
}