#include "Point.h"

Point::Point(int id, sf::Vector2f position)
{
	background.setSize(sf::Vector2f(20.0f, 20.0f));
	background.setOrigin(sf::Vector2f(10.0f, 10.0f));
	background.setTexture(&Resources::get().texture(TextureResourceType::POINT_NORMAL));
	soundPressed.setBuffer(Resources::get().sound(SoundResourceType::BUTTON_PRESSED));

	this->id = id;
	setPosition(position);

	disable();
}

void Point::update(sf::RenderWindow &window)
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
	case PointState::NORMAL:
		if (isMouseOver(window)) 
		{
			if (justMousePressed) 
			{
				state = PointState::PRESSED;
				updateBackground();
			}
			else 
			{
				if (!isMousePressed()) 
				{
					state = PointState::HOVER;
					updateBackground();
				}
			}
		}
		break;
	case PointState::HOVER:
		if (justMousePressed) 
		{
			state = PointState::PRESSED;
			updateBackground();
		}
		else 
		{
			if (!isMouseOver(window)) 
			{
				state = PointState::NORMAL;
				updateBackground();
			}
		}
		break;
	case PointState::PRESSED:
		if (!isMouseOver(window)) 
		{
			state = PointState::NORMAL;
			updateBackground();
		}
		else 
		{
			if (justMouseReleased) 
			{
				state = PointState::NORMAL;
				updateBackground();
				disable(); // TEMP
				justPressed = true;
				soundPressed.play();
			}
		}
		break;
	case PointState::DISABLED:
		break;
	}
}

void Point::draw(sf::RenderWindow & window)
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

void Point::updateBackground()
{
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
		break;
	case PointState::DISABLED:
		setBackground(Resources::get().texture(TextureResourceType::POINT_DISABLED));
		break;
	}
}

void Point::setBackground(sf::Texture & texture)
{
	background.setTexture(&texture);
}

void Point::enable()
{
	state = PointState::NORMAL;
	updateBackground();
}

void Point::disable()
{
	state = PointState::DISABLED;
	updateBackground();
}

bool Point::isEnabled()
{
	return !(state == PointState::DISABLED);
}

sf::Vector2f Point::getPosition()
{
	return position;
}

void Point::moveTo(sf::Vector2f position)
{
	setPosition(position);
}

void Point::reset()
{
	disable();
	linkedCoin = nullptr;
}

void Point::linkCoin(Coin * coin)
{
	this->linkedCoin = coin;
}

void Point::unlinkCoin()
{
	linkedCoin = nullptr;
}

Coin * Point::getLinkedCoin()
{
	return linkedCoin;
}

bool Point::hasLinkedCoin()
{
	return !(linkedCoin == nullptr);
}

void Point::enableFreeConnectedPoints()
{
	for (auto point : connectedPoints) 
	{
		if (!point->hasLinkedCoin()) 
		{
			point->enable();
		}
	}
}

bool Point::isMouseOver(sf::RenderWindow &window)
{
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	return background.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePositionFloat));
}

bool Point::isMousePressed()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

void Point::printConnections()
{
	std::cout << "p" << id << " <--> ";
	for (auto point : connectedPoints) {
		std::cout << "p" << point->getId() << " ";
	}
	std::cout << "\n";
}
