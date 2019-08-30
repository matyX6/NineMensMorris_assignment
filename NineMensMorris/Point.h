#pragma once
#include "Resources.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Coin.h"

class Point : public Button
{
private:
	int id;
	std::vector<Point *> connectedPoints;
	Coin *linkedCoin = nullptr;

public:
	Point(int id, sf::Vector2f position);
	int getId();
	void connectTo(Point &point);
	void moveTo(sf::Vector2f position);
	void reset();
	void linkCoin(Coin *coin);
	void unlinkCoin();
	Coin * getLinkedCoin();
	bool hasLinkedCoin();
	void enableFreeConnectedPoints();
	void printConnections();
};
