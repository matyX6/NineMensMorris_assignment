#include "Board.h"
#include <iostream>

Board::Board(sf::Vector2f position)
{
	background.setSize(sf::Vector2f(400.0f, 400.0f));
	setBackground(Resources::get().texture(TextureResourceType::BOARD));
	selectedCoin = nullptr;
	setPosition(position);
	setup();
}

void Board::update(sf::RenderWindow & window)
{
	justPlacedCoin = false;
	justSelectedCoin = nullptr;

	// check point clicks
	justSelectedPoint = nullptr;
	for (auto point : points) {
		if (point->isJustPressed()) 
		{
			justSelectedPoint = point;
		}
	}

	// check coin selects
	justSelectedCoin = nullptr;
	for (auto coin : coins) 
	{
		if (coin->isJustPressed()) 
		{
			justSelectedCoin = coin;
		}
	}

	// update children
	for (auto point : points) 
	{
		point->update(window);
	}
	for (auto coin : coins) 
	{
		coin->update(window);
	}
}

void Board::draw(sf::RenderWindow & window)
{
	window.draw(background);

	for (auto point : points) 
	{
		point->draw(window);
	}

	for (auto coin : coins) 
	{
		coin->draw(window);
	}
}

void Board::setup()
{
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
	// (rectangles/rings)
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
	points = { p0, p1, p2, p3, p4, p5, p6, p7, p8, p9,
		p10, p11, p12, p13, p14, p15, p16, p17, p18, p19,
		p20, p21, p22, p23 };

	// creating lines
	Line *l0 = new Line();
	Line *l1 = new Line();
	Line *l2 = new Line();
	Line *l3 = new Line();
	Line *l4 = new Line();
	Line *l5 = new Line();
	Line *l6 = new Line();
	Line *l7 = new Line();
	Line *l8 = new Line();
	Line *l9 = new Line();
	Line *l10 = new Line();
	Line *l11 = new Line();
	Line *l12 = new Line();
	Line *l13 = new Line();
	Line *l14 = new Line();
	Line *l15 = new Line();

	// forming lines
	l0->addPoint(p7);
	l0->addPoint(p0);
	l0->addPoint(p1);
	l1->addPoint(p1);
	l1->addPoint(p2);
	l1->addPoint(p3);
	l2->addPoint(p3);
	l2->addPoint(p4);
	l2->addPoint(p5);
	l3->addPoint(p5);
	l3->addPoint(p6);
	l3->addPoint(p7);
	// --
	l4->addPoint(p15);
	l4->addPoint(p8);
	l4->addPoint(p9);
	l5->addPoint(p9);
	l5->addPoint(p10);
	l5->addPoint(p11);
	l6->addPoint(p11);
	l6->addPoint(p12);
	l6->addPoint(p13);
	l7->addPoint(p13);
	l7->addPoint(p14);
	l7->addPoint(p15);
	// --
	l8->addPoint(p23);
	l8->addPoint(p16);
	l8->addPoint(p17);
	l9->addPoint(p17);
	l9->addPoint(p18);
	l9->addPoint(p19);
	l10->addPoint(p19);
	l10->addPoint(p20);
	l10->addPoint(p21);
	l11->addPoint(p21);
	l11->addPoint(p22);
	l11->addPoint(p23);
	// --
	l12->addPoint(p0);
	l12->addPoint(p8);
	l12->addPoint(p16);
	l13->addPoint(p2);
	l13->addPoint(p10);
	l13->addPoint(p18);
	l14->addPoint(p4);
	l14->addPoint(p12);
	l14->addPoint(p20);
	l15->addPoint(p6);
	l15->addPoint(p14);
	l15->addPoint(p22);

	// storing lines
	lines = { l0, l1, l2, l3, l4, l5, l6, l7, l8, l9,
			 l10, l11, l12, l13, l14, l15 };

	// create, place, and instance coins
	for (int i = 0; i < 9; i++) {
		Coin *w = new Coin(0, i, sf::Vector2f(50.0f, 140.0f + i * 20.0f));
		coins.push_back(w);
		Coin *b = new Coin(1, i, sf::Vector2f(550.0f, 140.0f + i * 20.0f));
		coins.push_back(b);
	}
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

void Board::disableAllPoints()
{
	for (auto point : points) 
	{
		point->disable();
	}
}

void Board::enableAllPoints()
{
	for (auto point : points)
	{
		point->enable();
	}
}

void Board::selectUnplacedCoin(int playerIndex)
{
	for (int i = coins.size() - 1; i >= 0; i--)
	{
		if (coins[i]->getPlayerIndex() == playerIndex && coins[i]->getCoinState() == CoinState::UNPLACED) 
		{
			coins[i]->select();
			selectedCoin = coins[i];
			return;
		}
	}
}

bool Board::hasUnplacedCoin()
{
	for (auto coin : coins) 
	{
		if (coin->getCoinState() == CoinState::UNPLACED) 
		{
			return true;
		}
	}

	return false;
}

void Board::reset()
{
	for (auto coin : coins)
	{
		coin->reset();
	}

	for (auto point : points) 
	{
		point->reset();
	}

	for (auto line : lines)
	{
		line->enable();
	}

	enableAllPoints();
	selectedCoin = nullptr;

	std::cout << "Board reset!\n";
}

bool Board::hasJustPlacedCoin()
{
	return justPlacedCoin;
}

bool Board::hasJustSelectedCoin()
{
	return (justSelectedCoin != nullptr);
}

Coin * Board::getJustSelectedCoin()
{
	return justSelectedCoin;
}

bool Board::hasJustSelectedPoint()
{
	return (justSelectedPoint != nullptr);
}

Point * Board::getJustSelectedPoint()
{
	return justSelectedPoint;
}

void Board::printLines()
{
	std::cout << "Lines:\n";
	for (auto line : lines) 
	{
		if (line->isCompleted()) 
		{
			std::cout << "Line [";
			line->printPoints();
			std::cout << "] completed (" << line->getCompletedPlayerIndex() << ").\n";
		}
	}
}

bool Board::hasLine()
{
	for (auto line : lines) 
	{
		if (line->isCompleted() && !line->isDisabled()) 
		{
			return true;
		}
	}

	return false;
}

bool Board::hasLineWithPlayerIndex(int playerIndex)
{
	for (auto line : lines) 
	{
		if (line->isCompleted() && line->getCompletedPlayerIndex() == playerIndex
			&& !line->isDisabled()) 
		{
			return true;
		}
	}

	return false;
}

void Board::disableLineWithPlayerIndex(int playerIndex)
{
	for (auto line : lines) 
	{
		if (line->isCompleted() && line->getCompletedPlayerIndex() == playerIndex
			&& !line->isDisabled()) 
		{
			line->disable();
			return;
		}
	}
}

void Board::disableLinesWithPlayerIndex(int playerIndex)
{
	for (auto line : lines) 
	{
		if (line->isCompleted() && line->getCompletedPlayerIndex() == playerIndex
			&& !line->isDisabled()) 
		{
			line->disable();
		}
	}
}

int Board::getLinePlayerIndex()
{
	for (auto line : lines) 
	{
		if (line->isCompleted()) 
		{
			return line->getCompletedPlayerIndex();
		}
	}

	return -1;
}

void Board::deselectCoin()
{
	selectedCoin->deselect();
	selectedCoin = nullptr;
}

void Board::deselectAllCoins()
{
	for (auto coin : coins)
	{
		coin->deselect();
	}
}

void Board::enablePlayerCoins(int playerIndex)
{
	for (auto coin : coins) 
	{
		if (coin->getPlayerIndex() == playerIndex)
		{
			coin->enable();
		}
	}
}

void Board::disableAllCoins()
{
	for (auto coin : coins) { coin->disable(); }
}

void Board::enableRemainingPoints()
{
	for (auto point : points)
	{
		if (point->getLinkedCoin() == nullptr) { point->enable(); }
	}
}

void Board::unlinkDisabledCoins()
{
	for (auto point : points) 
	{
		if (point->getLinkedCoin() != nullptr and point->getLinkedCoin()->isRemoved()) {
			point->unlinkCoin();
		}
	}
}

void Board::refreshLines()
{
	for (auto line : lines) 
	{
		line->refresh();
	}
}

bool Board::hasSelectedCoin()
{
	return (selectedCoin != nullptr);
}

Coin * Board::getSelectedCoin()
{
	return selectedCoin;
}

Point * Board::getPointWithSelectedCoin()
{
	for (auto point : points) 
	{
		if (point->hasLinkedCoin()) 
		{
			return point;
		}
	}
}

void Board::moveSelectedCoinToPoint(Point * point)
{
	// unlink
	if (selectedCoin->hasLinkedPoint()) 
	{
		selectedCoin->getLinkedPoint()->unlinkCoin();
	}
	selectedCoin->unlinkPoint();

	// move
	selectedCoin->setPosition(point->getPosition());

	// link
	selectedCoin->linkPoint(point);
	point->linkCoin(selectedCoin);

	selectedCoin = nullptr;
	point->disable();
}

void Board::placeSelectedCoin(Point * point)
{
	// move
	selectedCoin->setPosition(point->getPosition());

	// link
	selectedCoin->linkPoint(point);
	point->linkCoin(selectedCoin);

	// cleanup
	selectedCoin->deselect();
	selectedCoin->setCoinState(CoinState::PLACED);
	selectedCoin = nullptr;
	point->disable();
	justPlacedCoin = true;
}

void Board::setSelectedCoin(Coin * coin)
{
	selectedCoin = coin;
}

int Board::getNumberOfPlayerUnremovedCoins(int playerIndex)
{
	int count = 0;
	for (auto coin : coins)
	{
		if ((coin->getPlayerIndex() == playerIndex) && (coin->getCoinState() != CoinState::REMOVED))
		{
			count++;
		}
	}
	return count;
}

void Board::selectPlayerLineCoins(int playerIndex)
{
	for (auto line : lines)
	{
		if(line->isCompleted() && line->getCompletedPlayerIndex() == playerIndex && !line->isDisabled()) 
		{ 
			line->selectCoins();
		}
	}
}
