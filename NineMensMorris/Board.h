#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Coin.h"
#include "Line.h"
#include <vector>

class Board
{
private:
	sf::Vector2f position;
	std::vector<Point*> points;
	std::vector<Coin*> coins;
	std::vector<Line*> lines;
	sf::RectangleShape background;
	Coin *selectedCoin = nullptr;
	bool justPlacedCoin = false;
	bool justSelectedCoin = false;

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
	bool hasJustSelectedCoin();
	void printLines();
	bool hasLine();
	bool hasLineWithPlayerIndex(int playerIndex);
	void disableLineWithPlayerIndex(int playerIndex);
	void disableLinesWithPlayerIndex(int playerIndex);
	int getLinePlayerIndex();
	void deselectCoin();
	void enablePlayerCoins(int playerIndex);
	void removeSelectedCoin();
	void disableAllCoins();
	void enableRemainingPoints();
	void unlinkDisabledCoins();
	void refreshLines();
};