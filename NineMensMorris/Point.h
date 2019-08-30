#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Coin.h"

enum class PointState 
{
	NORMAL, HOVER, PRESSED, DISABLED
};

class Point
{
private:
	int id;
	sf::Vector2f position;
	std::vector<Point *> connectedPoints;
	sf::RectangleShape background;
	PointState state;
	sf::Sound soundPressed;
	Coin *linkedCoin = nullptr;
	bool disabled = true;

	bool justPressed;
	bool lastMousePressed = false;
	bool justMousePressed = false;
	bool justMouseReleased = false;

public:
	Point(int id, sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	int getId();
	void connectTo(Point &point);
	void setPosition(sf::Vector2f position);
	void setBackground(sf::Texture &texture);
	void enable();
	void disable();
	bool isEnabled();
	sf::Vector2f getPosition();
	void moveTo(sf::Vector2f position);
	void reset();
	void linkCoin(Coin *coin);
	void unlinkCoin();
	Coin * getLinkedCoin();
	bool hasLinkedCoin();
	void enableFreeConnectedPoints();
	void printConnections();

	bool isMouseOver(sf::RenderWindow &window);
	bool isMousePressed();
	bool isJustPressed();
	void updateBackground();
};
