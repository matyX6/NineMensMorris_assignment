#pragma once
#include "Resources.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

enum class PressState 
{
	NORMAL, HOVERED, PRESSED, DISABLED
};

class Button
{
public:
protected:
	sf::Vector2f size;
	sf::Vector2f position;
	sf::RectangleShape rect;
	sf::Sound soundPressed;

	sf::Texture *textureNormal;
	sf::Texture *textureHovered;
	sf::Texture *texturePressed;
	sf::Texture *textureDisabled;

	PressState pressState = PressState::NORMAL;

	bool justPressed = false;

	bool lastMousePressed = false;
	bool justMousePressed = false;
	bool justMouseReleased = false;

	void updateMouseStates();
	void updatePressState(sf::RenderWindow &window);

public:
	Button();
	~Button();
	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setSize(sf::Vector2f size);
	sf::Vector2f getSize();
	void setTexture(sf::Texture &texture);
	void updateBackground();

	void setPressState(PressState state);
	bool isMouseOver(sf::RenderWindow &window);
	bool isMousePressed();

	bool isJustPressed();
};
