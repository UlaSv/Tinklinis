#include <format>

#include "GameObjects.h"

GameObject::GameObject(int x, int y) 
{ 
	_x = x; 
	_y = y; 
}
int GameObject::GetX() const { return _x; }
int GameObject::GetY() const { return _y; }
void GameObject::XCoordinate(int step) { _x += step; }
void GameObject::YCoordinate(int step) { _y += step; }
void GameObject::DrawObject(sf::RenderWindow& appsas){};


Player1::Player1(int x, int y) : GameObject(x, y)
{
	_tPlayer1.loadFromFile("Resources/player.png");
	_sprPlayer1.setTexture(_tPlayer1);
	_radius = 52;
	_sprPlayer1.setOrigin(_radius, 25);
}
int Player1::operator--() const { return _radius; }
int Player1::operator - (int atstumas) const { return _x - atstumas; }
void Player1::DrawObject(sf::RenderWindow& appsas) 
{
	_sprPlayer1.setPosition(_x, _y);
	appsas.draw(_sprPlayer1); 
}

Player2::Player2(int x, int y) : GameObject(x, y)
{
	_tPlayer2.loadFromFile("Resources/player2.png");
	_sprPlayer2.setTexture(_tPlayer2);
	_radius = 52;
	_sprPlayer2.setOrigin(_radius, 25);
}
int Player2::operator--() const { return _radius; }
int Player2::operator - (int atstumas) const { return _x - atstumas; }
void Player2::DrawObject(sf::RenderWindow& appsas)
{ 
	_sprPlayer2.setPosition(_x, _y);
	appsas.draw(_sprPlayer2); 
}

Ball::Ball(int x, int y) : GameObject(x, y) 
{
	_tBall.loadFromFile("Resources/ball.png");
	_sprBall.setTexture(_tBall);
	_radius = 52;
	_sprBall.setOrigin(_radius, 25);
}
int Ball::GetRadius() const { return _radius; }
float Ball::BallStartY() const { return _y - 70; }
float Ball::BallEndY() const { return _y + 70; }
float Ball::BallX() const { return _x - 50; }
float Ball::BallX2() const { return _x + 50; }
void Ball::DrawObject(sf::RenderWindow& appsas) 
{  
	_sprBall.setPosition(_x, _y);
	appsas.draw(_sprBall); 
}

Net::Net(int x, int y):  GameObject(x, y) 
{
	_tNet.loadFromFile("Resources/Net.png");
	_sprNet.setTexture(_tNet);
	_sprNet.setPosition(_x,_y);
}

float Net::StartY() const { return _y; }
float Net::EndY() const { return _y + NET_HEIGHT; }
float Net::TopX() const { return _x; }
float Net::BottomX() const { return _x + NET_WIDTH; }
void Net::DrawObject(sf::RenderWindow& appsas) { appsas.draw(_sprNet); }

Text::Text()
{
	_font.loadFromFile("Resources/arcadeStyle.ttf");
	_text.setFont(_font);
	_text.setString("Arcade volleyball 2022");
	_text.setCharacterSize(40);
	_text.setFillColor(sf::Color::White);
	_text.setOutlineThickness(1);
	_text.setOutlineColor(sf::Color::Black);
	_text.setPosition(WINDOW_WIDTH / 3.5f, 5.f);

	_score1.setFont(_font);
	_score1.setCharacterSize(40);
	_score1.setFillColor(sf::Color::Cyan);
	_score1.setOutlineThickness(1);
	_score1.setOutlineColor(sf::Color::Black);
	_score1.setPosition(WINDOW_WIDTH / 5, 5.f);

	_score2.setFont(_font);
	_score2.setCharacterSize(40);
	_score2.setFillColor(sf::Color::Magenta);
	_score2.setOutlineThickness(1);
	_score2.setOutlineColor(sf::Color::Black);
	_score2.setPosition(WINDOW_WIDTH - 200, 5.f);
}
void Text::PrintText(sf::RenderWindow& appsas, int& taskai1, int& taskai2)
{
	appsas.draw(_text);
	_score1.setString(std::format("{:}", taskai1));
	appsas.draw(_score1);
	_score2.setString(std::format("{:}", taskai2));
	appsas.draw(_score2);
}
Contour::Contour()
{
	_linija.setSize(sf::Vector2f(950, 3));
	_linija.setPosition(20, 50.f);
	_line.push_back(_linija);

	_linija.setSize(sf::Vector2f(950, 3));
	_linija.setPosition(20, WINDOW_HEIGHT - 10);
	_line.push_back(_linija);

	_linija.setSize(sf::Vector2f(543, 3));
	_linija.setPosition(20, 50);
	_linija.setRotation(90.f);
	_line.push_back(_linija);

	_linija.setSize(sf::Vector2f(543, 3));
	_linija.setPosition(WINDOW_WIDTH - 28, 50);
	_linija.setRotation(90.f);
	_line.push_back(_linija);
}
void Contour::DrawContour(sf::RenderWindow& appsas)
{
	for (auto &vec: _line)
		appsas.draw(vec);
}