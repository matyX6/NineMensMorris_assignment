#include "Line.h"

Line::Line()
{
}

bool Line::isCompleted()
{
	if (points.empty()) { return false; }

	int playerIndex = -1;
	for (auto point : points) 
	{
		if (point->getLinkedCoin() == nullptr) { return false; }
		int coinPlayerIndex = point->getLinkedCoin()->getPlayerIndex();
		if (playerIndex == -1) { playerIndex = coinPlayerIndex; }
		else if (playerIndex != coinPlayerIndex) { return false; }
	}

	return true;
}

int Line::getCompletedPlayerIndex()
{
	if (points.empty()) { return 0; }
	if (points[0]->getLinkedCoin() == nullptr) { return 0; }
	return points[0]->getLinkedCoin()->getPlayerIndex();
}

void Line::addPoint(Point * point)
{
	points.push_back(point);
}

void Line::printPoints()
{
	for (auto point : points) {
		std::cout << point->getId() << " ";
	}
}

bool Line::isDisabled()
{
	return disabled;
}

void Line::disable()
{
	disabled = true;
}

void Line::enable()
{
	disabled = false;
}

void Line::refresh()
{
	if (!isCompleted()) { enable(); }
}

void Line::selectCoins()
{
	for (auto point : points)
	{
		point->getLinkedCoin()->select();
	}
}
