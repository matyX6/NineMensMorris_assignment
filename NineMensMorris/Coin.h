#pragma once
#include "Resources.h"
#include <iostream>
#include <SFML/Graphics.hpp>
class Coin
{
private:
	int playerIndex;
	sf::Vector2f position;
	sf::Vector2f homePosition;
	sf::RectangleShape background;
	sf::RectangleShape textureSelected;
	bool justPressed;
	bool selected;
	bool selectToggler;
	bool disabled;

	void setPlayerIndex(int playerIndex);

public:
	Coin(int playerIndex, sf::Vector2f position);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setPosition(sf::Vector2f position);
	bool isJustPressed();
	void setBackground(sf::Texture &texture);
	void enable();
	void disable();
	bool isEnabled();
	void goHome();
};

