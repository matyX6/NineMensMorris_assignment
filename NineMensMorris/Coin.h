#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <iostream>

enum class CoinState 
{
	UNPLACED,
	PLACED,
	REMOVED,
};

enum class PressState2 
{
	NORMAL, HOVER, PRESSED, DISABLED
};

class Point;

class Coin
{
private:
	int playerIndex = -1;
	int n = -1;
	CoinState state;
	PressState2 pressState;
	sf::Vector2f position;
	sf::Vector2f homePosition;
	sf::RectangleShape background;
	sf::RectangleShape textureSelected;
	sf::Sound soundRemoved;
	Point *linkedPoint = nullptr;
	bool selected = false;
	bool selectToggler = false;

	bool justPressed = false;
	bool lastMousePressed = false;
	bool justMousePressed = false;
	bool justMouseReleased = false;

	void setPlayerIndex(int playerIndex);

public:
	Coin(int n, int playerIndex, sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void goHome();
	void setBackground(sf::Texture &texture);
	void enable();
	void disable();
	bool isEnabled();
	void select();
	void deselect();
	bool isSelected();
	int getPlayerIndex();
	void reset();
	void remove();
	bool isRemoved();
	CoinState getState();
	void setState(CoinState state);
	void linkPoint(Point *point);
	Point *getLinkedPoint();
	void unlinkPoint();
	bool hasLinkedPoint();

	bool isMouseOver(sf::RenderWindow &window);
	bool isMousePressed();
	bool isJustPressed();
	void updateBackground();
};

