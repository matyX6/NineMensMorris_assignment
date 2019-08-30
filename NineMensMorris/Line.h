#pragma once
#include "Point.h"
#include "Coin.h"
#include <vector>

class Line
{
private:
	std::vector<Point *> points;
	bool disabled = false;

public:
	Line();
	bool isCompleted();
	int getCompletedPlayerIndex();
	void addPoint(Point *point);
	void printPoints();
	bool isDisabled();
	void disable();
	void enable();
	void refresh();
	void selectCoins();
};

