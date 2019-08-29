#pragma once
#include "Point.h"
#include "Coin.h"
#include <vector>

class Line
{
private:
	std::vector<Point *> points;

public:
	Line();
	bool isCompleted();
	int getCompletedPlayerIndex();
	void addPoint(Point *point);
	void printPoints();
};

