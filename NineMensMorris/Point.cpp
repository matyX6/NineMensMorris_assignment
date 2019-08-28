#include "Point.h"



Point::Point(int id, sf::Vector2f position)
{
	background.setSize(sf::Vector2f(20.0f, 20.0f));
	background.setOrigin(sf::Vector2f(10.0f, 10.0f));
	background.setTexture(&Resources::get().texture(TextureResourceType::POINT_NORMAL));
	soundPressed.setBuffer(Resources::get().sound(AudioResourceType::BUTTON_PRESSED));
	this->id = id;
	setPosition(position);
	disable();
}

void Point::update(sf::RenderWindow &window)
{
	justPressed = false;
	if (!disabled)
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
		PointState newState = PointState::NORMAL;
		if (background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat)))
		{
			newState = PointState::HOVER;

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				newState = PointState::PRESSED;
			}
		}
		if (state != newState)
		{
			setState(newState);
		}
	}
}

void Point::draw(sf::RenderWindow &window)
{
	window.draw(background);
}

int Point::getId()
{
	return id;
}

void Point::connectTo(Point &point)
{
	connectedPoints.push_back(&point);
	point.connectedPoints.push_back(this);
}

void Point::setPosition(sf::Vector2f position)
{
	this->position = position;
	background.setPosition(position);
}

bool Point::isJustPressed()
{
	return justPressed;
}

void Point::setState(PointState state)
{
	this->state = state;

	switch (state)
	{
	case PointState::NORMAL:
		setBackground(Resources::get().texture(TextureResourceType::POINT_NORMAL));
		break;
	case PointState::HOVER:
		setBackground(Resources::get().texture(TextureResourceType::POINT_HOVER));
		break;
	case PointState::PRESSED:
		setBackground(Resources::get().texture(TextureResourceType::POINT_PRESSED));
		justPressed = true;
		soundPressed.play();
		disable();
		break;
	default:
		break;
	}
}

void Point::setBackground(sf::Texture &texture)
{
	background.setTexture(&texture);
}

void Point::enable()
{
	disabled = false;
	setBackground(Resources::get().texture(TextureResourceType::POINT_NORMAL));;
}

void Point::disable()
{
	disabled = true;
	setBackground(Resources::get().texture(TextureResourceType::POINT_PRESSED));
}

bool Point::isEnabled()
{
	return !disabled;
}

sf::Vector2f Point::getPosition()
{
	return position;
}

void Point::moveTo(sf::Vector2f position)
{
	setPosition(position);
}



