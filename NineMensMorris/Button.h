#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

enum class ButtonState {
	NORMAL, HOVER, PRESSED
};

class Button
{
	// variables
public:
private:
	ButtonState state;
	sf::Vector2f position;
	sf::Text text;
	sf::RectangleShape background;
	sf::Sound soundPressed;

	bool justPressed;

	// methods
public:
	Button();
	~Button();
	Button(sf::Vector2f position, sf::String text);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	bool isJustPressed();
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setBackground(sf::Texture &texture);
	void setText(sf::String string);
	sf::String getText();
	void setState(ButtonState state);
private:
	void centerText();
};
