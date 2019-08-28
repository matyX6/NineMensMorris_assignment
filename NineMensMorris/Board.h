#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Coin.h"
#include <vector>

class Board
{
private:
	sf::Vector2f position;
	std::vector<Point*> points;
	std::vector<Coin*> coinsWhite;
	std::vector<Coin*> coinsBlack;
	sf::RectangleShape background;
	Coin *selectedCoin;
	bool justPlacedCoin;
	int currentPlayerIndex;

public:
	Board(sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setBackground(sf::Texture &texture);
	void setPosition(sf::Vector2f position);
	void disableAllPoints();
	void enableAllPoints();
	void selectCoinFromStack(int playerIndex, int coinIndex);
	void reset();
	bool hasJustPlacedCoin();
};