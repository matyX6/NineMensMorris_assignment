#include "Text.h"

Text::Text()
{
	this->text.setFont(Resources::get().font(FontResourceType::MAIN));
	this->text.setCharacterSize(20);
}

Text::Text(sf::Vector2f position, sf::String text)
{
	this->text.setFont(Resources::get().font(FontResourceType::MAIN));
	this->text.setCharacterSize(20);

	setPosition(position);
	setText(text);
}

void Text::update(sf::RenderWindow & windows)
{

}

void Text::draw(sf::RenderWindow & window)
{
	window.draw(text);
}

void Text::setPosition(sf::Vector2f position)
{
	this->position = position;
	updateTextPlacement();
}

void Text::setText(std::string string)
{
	text.setString(string);
	updateTextPlacement();
}

void Text::updateTextPlacement()
{
	sf::Vector2f textHalfSize(text.getGlobalBounds().width *0.5,
		text.getGlobalBounds().height *0.5f);
	sf::Vector2f offsetFix(0.0f, text.getLocalBounds().top);
	text.setPosition(position - textHalfSize - offsetFix);
}
