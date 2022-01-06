#include <SFML/Graphics.hpp>
#include <format>
#include <cmath>

#include "Objects.h"
#include "Utils.h"

using namespace sf;
using namespace std;

void UpdatePositions(Player& player, Player& player2, Net& net, Ball& ball, float& stepX)
{
	const float dx = 5.0f;
	const float dy = 10.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player.x -= dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.x += dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.y -= dy;
		if (player.y <= 450)
			player.y = GROUND_Y;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player2.x -= dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player2.x += dx;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		player2.y -= dy;
		if (player2.y <= 450)
			player2.y = GROUND_Y;
	}

	if (player.x >= net.x - 95)
		player.x = net.x - 95;

	if (player.x < 20)
		player.x = 20;

	if (player2.x <= net.x + 10)
		player2.x = net.x + 10;

	if (player2.x >= WINDOW_WIDTH - 115)
		player2.x = WINDOW_WIDTH - 115;

	if (nmUtils::InOnNet(ball, net))
		stepX = -7;
}

int main()
{
	RenderWindow app(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tenisas");
	app.setFramerateLimit(60);

	Texture tBackground, tPlayer1, tNet, tPlayer2, tBall;
	tBackground.loadFromFile("Resources/background.png");
	tPlayer1.loadFromFile("Resources/player.png");
	tPlayer2.loadFromFile("Resources/player2.png");
	tNet.loadFromFile("Resources/Net.png");
	tBall.loadFromFile("Resources/ball.png");

	sf::Font font;
	font.loadFromFile("Resources/arcadeStyle.ttf");

	sf::Text text;
	text.setFont(font);
	text.setString("Arcade volleyball 2022");
	text.setCharacterSize(40);
	text.setFillColor(Color::White);
	text.setOutlineThickness(1);
	text.setOutlineColor(Color::Black);
	text.setPosition(WINDOW_WIDTH / 3.5f, 5.f);

sf:RectangleShape line;
	line.setSize(sf::Vector2f(950, 3));
	line.setPosition(20, 50.f);

	RectangleShape line2;
	line2.setSize(sf::Vector2f(950, 3));
	line2.setPosition(20, WINDOW_HEIGHT - 10);

	RectangleShape line3;
	line3.setSize(sf::Vector2f(543, 3));
	line3.setPosition(20, 50);
	line3.setRotation(90.f);

	RectangleShape line4;
	line4.setSize(sf::Vector2f(543, 3));
	line4.setPosition(WINDOW_WIDTH - 28, 50);
	line4.setRotation(90.f);


	Sprite sprBackground(tBackground);
	Sprite sprPlayer(tPlayer1);
	Sprite sprPlayer2(tPlayer2);
	Sprite sprNet(tNet);
	Sprite sprBall(tBall);

	Player player;
	player.x = WINDOW_WIDTH / 6;
	player.y = GROUND_Y;

	Player player2;
	player2.x = WINDOW_WIDTH / 6 + WINDOW_WIDTH / 2;
	player2.y = GROUND_Y;

	Net net;
	net.x = WINDOW_WIDTH / 2 - 10;
	net.y = GROUND_Y - 200;

	Ball ball;
	ball.x = WINDOW_WIDTH / 6;
	ball.y = GROUND_Y - 100;

	float stepX = 7.0f;
	float stepY = 7.0f;

	while (app.isOpen())
	{
		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();
		}

		UpdatePositions(player, player2, net, ball, stepX);

		ball.x += stepX;
		ball.y += stepY;

		if (sprBall.getPosition().x > WINDOW_WIDTH - BALL_WIDTH - 40)
		{
			stepX = -7;
		}
		if (sprBall.getPosition().y > WINDOW_HEIGHT - BALL_HEIGHT - 15)
		{
			stepY = -7;
		}
		if (sprBall.getPosition().x < 20)
		{
			stepX = 7;
		}
		if (sprBall.getPosition().y < 55)
		{
			stepY = 7;
		}

		float x1, y1, x2, y2, xd, yd, distance, ballRadius, playerRadius;
		float x2_2, y2_2, xd_2, yd_2, distance2, player2Radius;
		x1 = sprBall.getPosition().x;
		y1 = sprBall.getPosition().y;
		x2 = sprPlayer.getPosition().x;
		y2 = sprPlayer.getPosition().y;
		x2_2 = sprPlayer2.getPosition().x;
		y2_2 = sprPlayer2.getPosition().y;
		ballRadius = 52;
		playerRadius = 53;
		player2Radius = 53;

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

		app.draw(sprBackground);

		sprPlayer.setPosition(player.x, player.y);
		app.draw(sprPlayer);
		sprPlayer2.setPosition(player2.x, player2.y);
		app.draw(sprPlayer2);
		sprBall.setPosition(ball.x, ball.y);
		app.draw(sprBall);
		sprNet.setPosition(net.x, net.y);
		app.draw(sprNet);

		app.draw(text);
		app.draw(line);
		app.draw(line2);
		app.draw(line3);
		app.draw(line4);

		app.display();
	}

	return 0;
}
