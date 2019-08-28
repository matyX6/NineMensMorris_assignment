#include "Point.h"



Point::Point(int id, sf::Vector2f position)
{
	background.setSize(sf::Vector2f(20.0f, 20.0f));
	background.setOrigin(sf::Vector2f(10.0f, 10.0f));
	background.setTexture(&Resources::get().texture(TextureResourceType::POINT_NORMAL));
	this->id = id;
	setPosition(position);
}

void Point::update(sf::RenderWindow &window)
{

}

void Point::draw(sf::RenderWindow &window)
{
	window.draw(background);
}

int Point::getId()
{
	return id;
}

void Point::connectTo(Point &point)
{
	connectedPoints.push_back(&point);
	point.connectedPoints.push_back(this);
}

void Point::setPosition(sf::Vector2f position)
{
	this->position = position;
	background.setPosition(position);
}



