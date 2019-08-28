#include "Board.h"
#include "Resources.h"
#include <iostream>

Board::Board(sf::Vector2f position)
{
	background.setSize(sf::Vector2f(400.0f, 400.0f));
	setBackground(Resources::get().texture(TextureResourceType::BOARD));
	setPosition(position);
}

void Board::update(sf::RenderWindow &window)
{
}

void Board::draw(sf::RenderWindow &window)
{
	window.draw(background);
}

void Board::addPoint(int id, sf::Vector2f position)
{
	Point *p = new Point(id, position);
	points.push_back(p);
	std::cout << "Point " << p->getId() << " added to board!\n";
}

void Board::addConnection(Point & p1, Point & p2)
{
}

void Board::setBackground(sf::Texture &texture)
{
	background.setTexture(&texture);
}

void Board::setPosition(sf::Vector2f position)
{
	this->position = position;

	background.setPosition(position);
}
