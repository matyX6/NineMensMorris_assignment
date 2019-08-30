#pragma once
#include "Resources.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <iostream>

enum class CoinState 
{
	UNPLACED,
	PLACED,
	REMOVED,
};

class Point;

class Coin : public Button
{
private:
	int playerIndex = -1;
	int n = -1;
	sf::Texture *textureNormal2;
	sf::Texture *textureHovered2;
	sf::Texture *texturePressed2;
	sf::Texture *textureDisabled2;
	CoinState coinState;
	sf::Vector2f homePosition;
	sf::Sound soundRemoved;
	sf::RectangleShape rectSelected;

	Point *linkedPoint = nullptr;
	bool selected = false;

public:
	Coin(int n, int playerIndex, sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setPosition(sf::Vector2f position);

	void select();
	void deselect();
	bool isSelected();

	void setPlayerIndex(int playerIndex);
	int getPlayerIndex();

	void remove();
	bool isRemoved();

	void setCoinState(CoinState state);
	CoinState getCoinState();

	Point *getLinkedPoint();
	bool hasLinkedPoint();
	void linkPoint(Point *point);
	void unlinkPoint();

	void reset();

	void updateBackground();
};
