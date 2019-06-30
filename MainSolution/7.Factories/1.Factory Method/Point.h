#ifndef _POINT_H__
#define _POINT_H__

#include <math.h>

class Point
{
	Point(int x,int y) 
		:_x(x),
		_y(y){}

public:

	int get_x() const{
		return _x;
	}

	int get_y() const{
		return _y;
	}

	void print()const{
		std::cout << _x << ":" << _y << std::endl;
	}

public:

	static Point CreateCartesianPoint(int x,int y) {
		return Point(x,y);
	}

	static Point CreatePolarPoint(int r,int theta) {
		return Point(r*cos(theta),r*sin(theta));
	}

private:
	int _x;
	int _y;
};

#endif // !_POINT_H__
