#pragma once
#include "Resources.h"
#include "Point.h"
#include "Coin.h"
#include "Line.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
private:
	sf::Vector2f position;
	std::vector<Point *> points;
	std::vector<Coin *> coins;
	std::vector<Line *> lines;
	sf::RectangleShape background;
	Coin *selectedCoin = nullptr;
	bool justPlacedCoin = false;
	Coin *justSelectedCoin = nullptr;
	Point *justSelectedPoint = nullptr;

public:
	Board(sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setup();
	void setBackground(sf::Texture &texture);
	void setPosition(sf::Vector2f position);
	void disableAllPoints();
	void enableAllPoints();
	void selectUnplacedCoin(int playerIndex);
	bool hasUnplacedCoin();
	void reset();
	bool hasJustPlacedCoin();
	void printLines();
	bool hasLine();
	bool hasLineWithPlayerIndex(int playerIndex);
	void disableLineWithPlayerIndex(int playerIndex);
	void disableLinesWithPlayerIndex(int playerIndex);
	int getLinePlayerIndex();
	void deselectCoin();
	void deselectAllCoins();
	void enablePlayerPlacedCoins(int playerIndex);
	void disableAllCoins();
	void enableRemainingPoints();
	void unlinkDisabledCoins();
	void refreshLines();
	bool hasSelectedCoin();
	Coin *getSelectedCoin();
	Point *getPointWithSelectedCoin();
	void moveSelectedCoinToPoint(Point *point);
	void placeSelectedCoin(Point *point);
	void setSelectedCoin(Coin *coin);
	int getNumberOfPlayerUnremovedCoins(int playerIndex);
	void selectPlayerLineCoins(int playerIndex);

	bool hasJustSelectedCoin();
	Coin *getJustSelectedCoin();

	bool hasJustSelectedPoint();
	Point *getJustSelectedPoint();
};
