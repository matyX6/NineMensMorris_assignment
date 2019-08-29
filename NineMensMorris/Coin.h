#pragma once
#include "Resources.h"
#include <iostream>
#include <SFML/Graphics.hpp>

enum class CoinState
{
	UNPLACED,
	PLACED,
	REMOVED
};

class Coin
{
private:
	int playerIndex = -1;
	int n = -1;
	CoinState state;
	sf::Vector2f position;
	sf::Vector2f homePosition;
	sf::RectangleShape background;
	sf::RectangleShape textureSelected;
	sf::Sound soundRemoved;
	bool justPressed = false;
	bool selected = false;
	bool selectToggler = false;
	bool disabled = true;

	void setPlayerIndex(int playerIndex);

public:
	Coin(int n, int playerIndex, sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setPosition(sf::Vector2f position);
	void goHome();
	void setBackground(sf::Texture &texture);
	void enable();
	void disable();
	bool isEnabled();
	void select();
	void deselect();
	bool isSelected();
	bool isJustPressed();
	int getPlayerIndex();
	void reset();
	void remove();
	bool isRemoved();
	CoinState getState();
	void setState(CoinState state);
};

