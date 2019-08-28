#include "Board.h"
#include "Resources.h"
#include <iostream>

Board::Board(sf::Vector2f position)
{
	background.setSize(sf::Vector2f(400.0f, 400.0f));
	setBackground(Resources::get().texture(TextureResourceType::BOARD));
	setPosition(position);

	// creating points
	Point *p0 = new Point(0, sf::Vector2f(300.0f, 100.0f));
	Point *p1 = new Point(1, sf::Vector2f(450.0f, 100.0f));
	Point *p2 = new Point(2, sf::Vector2f(450.0f, 250.0f));
	Point *p3 = new Point(3, sf::Vector2f(450.0f, 400.0f));
	Point *p4 = new Point(4, sf::Vector2f(300.0f, 400.0f));
	Point *p5 = new Point(5, sf::Vector2f(150.0f, 400.0f));
	Point *p6 = new Point(6, sf::Vector2f(150.0f, 250.0f));
	Point *p7 = new Point(7, sf::Vector2f(150.0f, 100.0f));
	// --
	Point *p8 = new Point(8, sf::Vector2f(300.0f, 150.0f));
	Point *p9 = new Point(9, sf::Vector2f(400.0f, 150.0f));
	Point *p10 = new Point(10, sf::Vector2f(400.0f, 250.0f));
	Point *p11 = new Point(11, sf::Vector2f(400.0f, 350.0f));
	Point *p12 = new Point(12, sf::Vector2f(300.0f, 350.0f));
	Point *p13 = new Point(13, sf::Vector2f(200.0f, 350.0f));
	Point *p14 = new Point(14, sf::Vector2f(200.0f, 250.0f));
	Point *p15 = new Point(15, sf::Vector2f(200.0f, 150.0f));
	// --
	Point *p16 = new Point(16, sf::Vector2f(300.0f, 200.0f));
	Point *p17 = new Point(17, sf::Vector2f(350.0f, 200.0f));
	Point *p18 = new Point(18, sf::Vector2f(350.0f, 250.0f));
	Point *p19 = new Point(19, sf::Vector2f(350.0f, 300.0f));
	Point *p20 = new Point(20, sf::Vector2f(300.0f, 300.0f));
	Point *p21 = new Point(21, sf::Vector2f(250.0f, 300.0f));
	Point *p22 = new Point(22, sf::Vector2f(250.0f, 250.0f));
	Point *p23 = new Point(23, sf::Vector2f(250.0f, 200.0f));

	// connecting points
	// (rectangles)
	p0->connectTo(*p1);
	p1->connectTo(*p2);
	p2->connectTo(*p3);
	p3->connectTo(*p4);
	p4->connectTo(*p5);
	p5->connectTo(*p6);
	p6->connectTo(*p7);
	p7->connectTo(*p0);
	// --
	p8->connectTo(*p9);
	p9->connectTo(*p10);
	p10->connectTo(*p11);
	p11->connectTo(*p12);
	p12->connectTo(*p13);
	p13->connectTo(*p14);
	p14->connectTo(*p15);
	p15->connectTo(*p8);
	// --
	p16->connectTo(*p17);
	p17->connectTo(*p18);
	p18->connectTo(*p19);
	p19->connectTo(*p20);
	p20->connectTo(*p21);
	p21->connectTo(*p22);
	p22->connectTo(*p23);
	p23->connectTo(*p16);
	// (crossings)
	p0->connectTo(*p8);
	p2->connectTo(*p10);
	p4->connectTo(*p12);
	p6->connectTo(*p14);
	// --
	p8->connectTo(*p16);
	p10->connectTo(*p18);
	p12->connectTo(*p20);
	p14->connectTo(*p22);

	// storing points
	points.push_back(p0);
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);
	points.push_back(p5);
	points.push_back(p6);
	points.push_back(p7);
	// --
	points.push_back(p8);
	points.push_back(p9);
	points.push_back(p10);
	points.push_back(p11);
	points.push_back(p12);
	points.push_back(p13);
	points.push_back(p14);
	points.push_back(p15);
	// --
	points.push_back(p16);
	points.push_back(p17);
	points.push_back(p18);
	points.push_back(p19);
	points.push_back(p20);
	points.push_back(p21);
	points.push_back(p22);
	points.push_back(p23);
}

void Board::update(sf::RenderWindow &window)
{
	for (auto point : points)
	{
		point->update(window);
	}
}

void Board::draw(sf::RenderWindow &window)
{
	window.draw(background);

	for (auto point : points)
	{
		point->draw(window);
	}
}

void Board::addPoint(int id, sf::Vector2f position)
{
	Point *p = new Point(id, position);
	points.push_back(p);
	std::cout << "Point " << p->getId() << " added to board!\n";
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
