#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include <vector>

class Board
{
private:
	sf::Vector2f position;
	std::vector<Point*> points;
	sf::RectangleShape background;

public:
	Board(sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void addPoint(int id, sf::Vector2f position);
	void setBackground(sf::Texture &texture);
	void setPosition(sf::Vector2f position);
};