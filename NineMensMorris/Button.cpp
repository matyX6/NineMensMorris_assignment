#include "Button.h"

Button::Button()
{
	soundPressed.setBuffer(Resources::get().sound(SoundResourceType::BUTTON_PRESSED));
}

Button::~Button()
{
}

void Button::update(sf::RenderWindow & window, int delta)
{
	updateMouseStates();
	updatePressState(window);
}

void Button::draw(sf::RenderWindow & window)
{
	window.draw(rect);
}

void Button::setPosition(sf::Vector2f position)
{
	this->position = position;
	rect.setPosition(position);
}

sf::Vector2f Button::getPosition()
{
	return position;
}

void Button::setSize(sf::Vector2f size)
{
	this->size = size;
	rect.setSize(size);
}

sf::Vector2f Button::getSize()
{
	return size;
}

void Button::setTexture(sf::Texture &texture)
{
	rect.setTexture(&texture);
}

void Button::updateBackground()
{
	switch (pressState)
	{
	case PressState::NORMAL:
		setTexture(*textureNormal);
		break;
	case PressState::HOVERED:
		setTexture(*textureHovered);
		break;
	case PressState::PRESSED:
		setTexture(*texturePressed);
		break;
	case PressState::DISABLED:
		setTexture(*textureDisabled);
		break;
	}
}

void Button::setPressState(PressState state)
{
	pressState = state;
	updateBackground();
}

bool Button::isMouseOver(sf::RenderWindow & window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	return rect.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat));
}

bool Button::isMousePressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

bool Button::isJustPressed()
{
	return justPressed;
}

void Button::setCentered(bool value)
{
	centered = value;
	if (centered)
	{
		rect.setOrigin(sf::Vector2f(size.x * 0.5f, size.y * 0.5f));
	}
	else
	{
		rect.setOrigin(sf::Vector2f(0.0f, 0.0f));
	}
}

void Button::disable()
{
	setPressState(PressState::DISABLED);
}

void Button::enable()
{
	setPressState(PressState::NORMAL);
}

bool Button::isEnabled()
{
	return (pressState != PressState::DISABLED);
}

void Button::updateMouseStates()
{
	justPressed = false;
	justMousePressed = false;
	justMouseReleased = false;

	if (lastMousePressed != isMousePressed()) 
	{
		if (lastMousePressed == false) { justMousePressed = true; }
		else { justMouseReleased = true; }
		lastMousePressed = isMousePressed();
	}
}

void Button::updatePressState(sf::RenderWindow &window)
{
	justPressed = false;

	switch (pressState)
	{
	case PressState::NORMAL:
		if (isMouseOver(window)) 
		{
			if (justMousePressed) 
			{
				setPressState(PressState::PRESSED);
			}
			else 
			{
				if (!isMousePressed()) 
				{
					setPressState(PressState::HOVERED);
				}
			}
		}
		break;
	case PressState::HOVERED:
		if (justMousePressed)
		{
			setPressState(PressState::PRESSED);
		}
		else
		{
			if (!isMouseOver(window))
			{
				setPressState(PressState::NORMAL);
			}
		}
		break;
	case PressState::PRESSED:
		if (!isMouseOver(window)) 
		{
			setPressState(PressState::NORMAL);
		}
		else
		{
			if (justMouseReleased) 
			{
				setPressState(PressState::NORMAL);
				justPressed = true;
				soundPressed.play();
			}
		}
		break;
	}
}
