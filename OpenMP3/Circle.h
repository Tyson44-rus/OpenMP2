#pragma once
class Point {
public:
	int x, y;
	Point() {};
	~Point() {};
};

class Circle
{
public:
	Point point1;
	Point point2;
	int maxX, maxY, minX, minY, R;
	Circle() {};
	~Circle() {};
};

