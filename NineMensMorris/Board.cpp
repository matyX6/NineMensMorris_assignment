#include "Board.h"
#include <iostream>

Board::Board(sf::Vector2f position)
{
	// loading resources
	backgroundTexture.loadFromFile("./textures/board.png");

	background.setSize(sf::Vector2f(400.0f, 400.0f));
	setBackground(backgroundTexture);

	setPosition(position);
}

void Board::update(sf::RenderWindow & window)
{
}

void Board::draw(sf::RenderWindow & window)
{
	window.draw(background);
}

void Board::addPoint(int id, sf::Vector2f position)
{
	Point p(id, position);
	points.push_back(p);
	std::cout << "Point " << p.getId() << " added to board!\n";
}

void Board::setBackground(sf::Texture texture)
{
	this->backgroundTexture = texture;
	background.setTexture(&backgroundTexture);
}

void Board::setPosition(sf::Vector2f position)
{
	this->position = position;

	background.setPosition(position);
}
