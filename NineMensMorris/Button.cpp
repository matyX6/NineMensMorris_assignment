#include "Button.h"
#include "Resources.h"

Button::Button()
{
}

Button::~Button()
{
}

Button::Button(sf::Vector2f position, sf::String text)
{
	background.setSize(sf::Vector2f(120.0f, 60.0f));
	soundPressed.setBuffer(Resources::get().sound(SoundResourceType::BUTTON_PRESSED));
	this->text.setFont(Resources::get().font(FontResourceType::MAIN));
	this->text.setCharacterSize(16.0f);
	justPressed = false;
	setState(ButtonState::NORMAL);
	setText(text);
	setPosition(position);
}

void Button::update(sf::RenderWindow &window)
{
	justPressed = false;

	// get mouse state
	justMousePressed = false;
	justMouseReleased = false;
	if (lastMousePressed != isMousePressed()) 
	{
		if (lastMousePressed == false) { justMousePressed = true; }
		else { justMouseReleased = true; }
		lastMousePressed = isMousePressed();
	}

	// states
	switch (state)
	{
	case ButtonState::NORMAL:
		if (isMouseOver(window)) 
		{
			if (justMousePressed) 
			{
				state = ButtonState::PRESSED;
				updateBackground();
			}
			else {
				if (!isMousePressed()) 
				{
					state = ButtonState::HOVER;
					updateBackground();
				}
			}
		}
		break;
	case ButtonState::HOVER:
		if (justMousePressed) 
		{
			state = ButtonState::PRESSED;
			updateBackground();
		}
		else {
			if (!isMouseOver(window)) 
			{
				state = ButtonState::NORMAL;
				updateBackground();
			}
		}
		break;
	case ButtonState::PRESSED:
		if (!isMouseOver(window)) 
		{
			state = ButtonState::NORMAL;
			updateBackground();
		}
		else 
		{
			if (justMouseReleased) 
			{
				state = ButtonState::NORMAL;
				updateBackground();
				justPressed = true;
				soundPressed.play();
			}
		}
		break;
	}
}

void Button::draw(sf::RenderWindow &window)
{
	window.draw(background);
	window.draw(text);
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
}
sf::String Button::getText()
{
	return text.getString();
}

void Button::setState(ButtonState state) 
{
	this->state = state;

	switch (state)
	{
	case ButtonState::NORMAL:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_NORMAL));
		break;
	case ButtonState::HOVER:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_HOVER));
		break;
	case ButtonState::PRESSED:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_PRESSED));
		justPressed = true;
		soundPressed.play();
		break;
	default:
		break;
	}
}

bool Button::isMouseOver(sf::RenderWindow & window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	return background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat));
}

bool Button::isMousePressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

void Button::updateBackground()
{
	switch (state)
	{
	case ButtonState::NORMAL:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_NORMAL));
		break;
	case ButtonState::HOVER:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_HOVER));
		break;
	case ButtonState::PRESSED:
		setBackground(Resources::get().texture(TextureResourceType::BUTTON_PRESSED));
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