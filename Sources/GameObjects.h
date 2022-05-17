#pragma once
#ifndef GameObje_H
#define GameObje_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Defines.h"

class GameObject
{
protected:
	int _x;
	int _y;

public:
	GameObject(int x, int y);
	virtual ~GameObject(){};
	int GetX() const;
	int GetY() const;
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
	int operator -- () const;
	int operator - (int atstumas) const;
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
	int operator --() const;
	int operator - (int atstumas) const;
	void DrawObject(sf::RenderWindow& appsas);
};

class Ball : public GameObject
{
private:
	int _radius;
	sf::Texture _tBall;
	sf::Sprite _sprBall;

public:
	Ball(int x, int y);
	virtual ~Ball() {};
	float BallStartY() const;
	float BallEndY() const;
	float BallX()const;
	float BallX2() const;
	int GetRadius() const;
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
	float StartY() const;
	float EndY() const;
	float TopX() const;
	float BottomX()const;
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
	std::vector <sf::RectangleShape> _line;
	sf::RectangleShape _linija;
public:
	Contour();
	~Contour() {};
	void DrawContour(sf::RenderWindow& appsas);
};
#endif