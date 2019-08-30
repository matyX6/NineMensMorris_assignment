#include "Point.h"

Point::Point(int id, sf::Vector2f position)
{
	textureNormal = &Resources::get().texture(TextureResourceType::POINT_NORMAL);
	textureHovered = &Resources::get().texture(TextureResourceType::POINT_HOVERED);
	texturePressed = &Resources::get().texture(TextureResourceType::POINT_PRESSED);
	textureDisabled = &Resources::get().texture(TextureResourceType::POINT_DISABLED);
	soundPressed.setBuffer(Resources::get().sound(SoundResourceType::BUTTON_PRESSED));
	setSize(sf::Vector2f(20.0f, 20.0f));
	setCentered(true);

	this->id = id;
	setPosition(position);

	disable();
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
	for (auto point : connectedPoints) {
		if (!point->hasLinkedCoin()) {
			point->enable();
		}
	}
}

void Point::printConnections()
{
	std::cout << "p" << id << " <--> ";
	for (auto point : connectedPoints) {
		std::cout << "p" << point->getId() << " ";
	}
	std::cout << "\n";
}
