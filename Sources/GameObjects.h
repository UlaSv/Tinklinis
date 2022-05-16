#pragma once
#ifndef GameObje_H
#define GameObje_H

#include <SFML/Graphics.hpp>
#include "Defines.h"

class GameObject
{
protected:
	int _x;
	int _y;

public:
	GameObject(int x, int y);
	virtual ~GameObject(){};
	int GetX();
	int GetY();
	void XCoordinate(int step);
	void YCoordinate(int step);
	virtual void DrawObject(sf::RenderWindow& appsas);
};

class Player1 : public GameObject
{
private:
	sf::Texture _tPlayer1;
	sf::Sprite _sprPlayer1;
	int _radius;

public:
	Player1(int x, int y);
	virtual ~Player1(){};
	int GetRadius();
	void DrawObject(sf::RenderWindow& appsas);
};

class Player2 : public GameObject
{
private:
	sf::Texture _tPlayer2;
	sf::Sprite _sprPlayer2;
	int _radius;

public:
	Player2(int x, int y);
	virtual ~Player2() {};
	int GetRadius();
	void DrawObject(sf::RenderWindow& appsas);
};

class Ball : public GameObject
{
private:
	float _stepX = 7.0f;
	float _stepY = 7.0f;
	int _radius;
	sf::Texture _tBall;
	sf::Sprite _sprBall;

public:
	Ball(int x, int y);
	virtual ~Ball() {};
	float BallStartY();
	float BallEndY();
	float BallX();
	float BallX2();
	int GetRadius();
	void DrawObject(sf::RenderWindow& appsas);
};

class Net : public GameObject
{
private:
	sf::Texture _tNet;
	sf::Sprite _sprNet;
public:
	Net(int x, int y);
	virtual ~Net(){};
	float StartY();
	float EndY();
	float TopX();
	float BottomX();
	void DrawObject(sf::RenderWindow& appsas);
};

class Text
{
private:
	sf::Font _font;
	sf::Text _text, _score1, _score2;
public:
	Text();
	~Text() {};
	void PrintText(sf::RenderWindow& appsas, int& taskai1, int& taskai2);
};

class Contour
{
private:
	sf::RectangleShape _line1, _line2, _line3, _line4;
public:
	Contour();
	~Contour() {};
	void DrawContour(sf::RenderWindow& appsas);
};
#endif