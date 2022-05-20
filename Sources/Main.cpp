#include <SFML/Graphics.hpp>
#include <cmath>
#include <algorithm>

#include "Objects.h"
#include "Utils.h"
#include "GameObjects.h"

int main()
{
	sf::RenderWindow app(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tenisas");
	app.setFramerateLimit(60);

	sf::Texture tBackground;
	tBackground.loadFromFile("Resources/background.png");
	sf::Sprite sprBackground(tBackground);

	Text tekstas;
	Contour remas;
	Player player1(WINDOW_WIDTH / 4, GROUND_Y, "Resources/player.png");
	Player player2(WINDOW_WIDTH / 4 + WINDOW_WIDTH / 2, GROUND_Y, "Resources/player2.png");
	Net net(WINDOW_WIDTH / 2 - 20, GROUND_Y - 220);
	Ball ball(WINDOW_WIDTH / 6, GROUND_Y - 100);

	GameObject* pPlayer1 = dynamic_cast<Player*>(&player1);
	GameObject* pPlayer2 = dynamic_cast<Player*>(&player2);
	GameObject* pNet = dynamic_cast<Net*>(&net);
	GameObject* pBall = dynamic_cast<Ball*>(&ball);

	int score1 = 0, score2=0;
	int stepX = 7, stepY = 7;

	while (app.isOpen())
	{
		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
		}

		nmUtils::UpdatePositions(player1, player2, net, ball, stepX, stepY);
		nmUtils::Collision(player1, player2, ball, stepX, stepY);
		nmUtils::Score(ball, net, score1, score2);
		
		app.clear();
		app.draw(sprBackground);
		
		tekstas.PrintText(app, score1, score2);
		remas += app;
		
		pPlayer1->DrawObject(app);
		pPlayer2->DrawObject(app);
		pNet->DrawObject(app);
		pBall->DrawObject(app);

		app.display();
	}
	return 0;
}
