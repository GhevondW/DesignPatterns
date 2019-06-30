#include <iostream>
#include "PointFactory.h"


int main() {

	Point p1 = PointFactory::CreateCartesianPoint(15,30);
	Point p2 = PointFactory::CreatePolarPoint(15,30);

	p1.print();
	p2.print();

	std::cin.get();
	return 0;
}