#include "Button.h"



Button::Button(sf::Vector2f position, sf::String text)
{

	//load textures and resources
	textFont.loadFromFile("./fonts/Splatch.ttf");
	textureNormal.loadFromFile("./textures/button-normal.png");
	textureHover.loadFromFile("./textures/button-hover.png");
	texturePressed.loadFromFile("./textures/button-pressed.png");

	//set button font
	this->text.setFont(textFont);

	//button background
	background.setSize(sf::Vector2f(120.0f, 60.0f));

	//set state
	justPressed = false;
	setState(ButtonState::NORMAL);

	setText(text);
	setPosition(position);
}

void Button::update(sf::Vector2i(mousePosition))
{
	//hover and press state check
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	ButtonState newState = ButtonState::NORMAL;

	if (background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat)))
	{
		newState = ButtonState::HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			newState = ButtonState::PRESSED;
		}
	}

	if (state != newState)
	{
		setState(newState);
	}
}

bool Button::isJustPressed()
{
	return justPressed;
}

void Button::setBackground(sf::Texture &texture)
{
	background.setTexture(&texture);
}

sf::Vector2f Button::getPosition()
{
	return position;
}

void Button::setPosition(sf::Vector2f position)
{
	this->position = position;

	background.setPosition(position);

	centerText();
}

void Button::setText(sf::String string)
{
	text.setString(string);
	centerText();
	text.setCharacterSize(16.0f);
}

void Button::draw(sf::RenderWindow &window)
{
	window.draw(background);
	window.draw(text);
}

void Button::setState(ButtonState state)
{
	this->state = state;

	switch (state)
	{
	case ButtonState::NORMAL:
		setBackground(textureNormal);
		break;
	case ButtonState::HOVER:
		setBackground(textureHover);
		break;
	case ButtonState::PRESSED:
		setBackground(texturePressed);
		justPressed = true;
		break;
	default:
		break;
	}
}

void Button::centerText() 
{
	sf::Vector2f textureHalfSize(background.getGlobalBounds().width * 0.5f,
		background.getGlobalBounds().height * 0.5f);
	sf::Vector2f textHalfSize(text.getGlobalBounds().width * 0.5f,
		text.getGlobalBounds().height * 0.5f);
	sf::Vector2f offsetFix(0.0f, text.getLocalBounds().top);
	text.setPosition(position + textureHalfSize - textHalfSize - offsetFix);
}
