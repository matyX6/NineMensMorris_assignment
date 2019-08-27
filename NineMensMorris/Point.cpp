#include "Point.h"



Point::Point(int id, sf::Vector2f position)
{
	this->id = id;
	this->position = position;
}

void Point::update(sf::RenderWindow &window)
{

}

void Point::draw(sf::RenderWindow &window)
{

}

int Point::getId()
{
	return id;
}



