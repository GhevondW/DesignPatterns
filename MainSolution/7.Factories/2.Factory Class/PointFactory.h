#ifndef _POINT_FACTORY_H__
#define _POINT_FACTORY_H__

#include "Point.h"

class PointFactory
{
public:

	static Point CreateCartesianPoint(int x,int y) {
		return Point(x,y);
	}

	static Point CreatePolarPoint(int r,int theta) {
		return Point(r*cos(theta),r*sin(theta));
	}

};


#endif // !_POINT_FACTORY_H__
