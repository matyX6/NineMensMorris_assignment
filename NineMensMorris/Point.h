#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Point
{
public:
	Point(int id, sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	int getId();
	
private:
	int id;
	sf::Vector2f position;
};

