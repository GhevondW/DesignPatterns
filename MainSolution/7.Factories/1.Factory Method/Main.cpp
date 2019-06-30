#include <iostream>

#include "Point.h"

int main() {

	Point p = Point::CreateCartesianPoint(5,6);
	Point p1 = Point::CreatePolarPoint(10,45);

	p.print();
	p1.print();
	std::cin.get();
	return 0;
}