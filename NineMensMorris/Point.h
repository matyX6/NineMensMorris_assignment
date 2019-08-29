#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"
#include "Coin.h"
#include <vector>
#include <iostream>

enum class PointState
{
	NORMAL, HOVER, PRESSED
};

class Point
{
private:
	int id;
	sf::Vector2f position;
	std::vector<Point *> connectedPoints;
	sf::RectangleShape background;
	PointState state;
	bool justPressed;
	sf::Sound soundPressed;
	bool disabled;
	Coin *coin = nullptr;

public:
	Point(int id, sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	int getId();
	void connectTo(Point &point);
	void setPosition(sf::Vector2f position);

	bool isJustPressed();
	void setState(PointState state);
	void setBackground(sf::Texture &texture);
	void enable();
	void disable();
	bool isEnabled();
	sf::Vector2f getPosition();
	void moveTo(sf::Vector2f position);
	void reset();
	void linkCoin(Coin *coin);
	Coin *getLinkedCoin();

	void printConnections()
	{
		for (auto point : connectedPoints)
		{
			std::cout << "p" << point->getId() << " ";
		}
		std::cout << "\n";
	}
};

