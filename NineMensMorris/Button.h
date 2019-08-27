#pragma once
#include <SFML/Graphics.hpp>

enum class ButtonState
{
	NORMAL, HOVER, PRESSED
};

class Button
{
public:
	Button();
	Button(sf::Vector2f position, sf::String text);

	void update(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);

	bool isJustPressed();

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();


	void setBackground(sf::Texture &texture);
	void setText(sf::String string);
	void setState(ButtonState state);

private:
	ButtonState state;
	sf::Vector2f position;
	sf::Text text;
	sf::RectangleShape background;

	bool justPressed;
	sf::Texture textureNormal;
	sf::Texture textureHover;
	sf::Texture texturePressed;
	sf::Font textFont;

	//method
	void centerText();
};

