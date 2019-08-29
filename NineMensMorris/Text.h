#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Resources.h"

class Text
{
private:
	sf::Vector2f position;
	sf::Text text;

	void updateTextPlacement();

public:
	Text();
	Text(sf::Vector2f position, sf::String text = "<...>");
	void update(sf::RenderWindow &windows);
	void draw(sf::RenderWindow &window);

	void setPosition(sf::Vector2f position);
	void setText(std::string string);
};

