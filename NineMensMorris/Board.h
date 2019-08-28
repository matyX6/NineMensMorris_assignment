#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include <vector>

struct Connection
{
	Point *point1;
	Point *point2;
};

class Board
{
private:
	sf::Vector2f position;
	std::vector<Point*> points;
	std::vector<Connection*> connections;
	sf::RectangleShape background;

public:
	Board(sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void addPoint(int id, sf::Vector2f position);
	void addConnection(Point &p1, Point &p2);
	void setBackground(sf::Texture &texture);
	void setPosition(sf::Vector2f position);
};