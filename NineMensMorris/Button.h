#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

enum class ButtonState 
{
	NORMAL, HOVER, PRESSED, DISABLED
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
	bool lastMousePressed = false;
	bool justMousePressed = false;
	bool justMouseReleased = false;

	// methods
public:
	Button();
	~Button();
	Button(sf::Vector2f position, sf::String text);
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setBackground(sf::Texture &texture);
	void setText(sf::String string);
	sf::String getText();
	bool isJustPressed();
	void setState(ButtonState state);
	bool isMouseOver(sf::RenderWindow &window);
	bool isMousePressed();
	void updateBackground();

private:
	void centerText();
};
