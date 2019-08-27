#include "Button.h"



Button::Button(sf::Vector2f position, sf::String text)
{
	//set button texture
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("./textures/button.png");
	setBackground(backgroundTexture);

	//set button font
	textFont.loadFromFile("./fonts/Splatch.ttf");
	this->text.setFont(textFont);

	//button background
	background.setSize(sf::Vector2f(120.0f, 60.0f));

	setPosition(position);
	setText(text);

}

void Button::update()
{
	//set text position by button background
	text.setPosition(background.getPosition());
}

void Button::setBackground(sf::Texture texture)
{
	this->backgroundTexture = texture;
	background.setTexture(&backgroundTexture);
}

sf::Vector2f Button::getPosition()
{
	return position;
}

void Button::setPosition(sf::Vector2f position)
{
	this->position = position;
	background.setPosition(position);
	text.setPosition(position);
}

void Button::setText(sf::String string)
{
	text.setString(string);
	text.setCharacterSize(16.0f);
}

void Button::draw(sf::RenderWindow &window)
{
	window.draw(background);
	window.draw(text);
}
