#ifndef _POINT_H__
#define _POINT_H__

#include <math.h>
#include <iostream>

class Point
{
	friend class PointFactory;
private:
	Point(int x, int y) 
		:_x(x),
		_y(y){}

public:

	void print()const {
		std::cout << "x:" << _x << ", y:" << _y << std::endl;
	}

private:
	int _x;
	int _y;
};


#endif // !_POINT_H__
