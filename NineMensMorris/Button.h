#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(sf::Vector2f position, sf::String text);
	void update();
	void draw(sf::RenderWindow &window);
	void setBackground(sf::Texture texture);
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
	void setText(sf::String string);

private:
	sf::Vector2f position;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font textFont;
	sf::Text text;
};

