#pragma once
#include "Resources.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuButton : public Button
{
public:
private:
	sf::Text text;

public:
	MenuButton();
	MenuButton(sf::Vector2f position, sf::String text);
	void draw(sf::RenderWindow &window);

	void setText(sf::String string);
	sf::String getText();

private:
	void centerText();
};
