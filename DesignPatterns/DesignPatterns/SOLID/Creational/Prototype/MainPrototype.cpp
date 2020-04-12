#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <set>
#include <unordered_map>
#include <algorithm>
#include "Shape.h"

int main()
{
	Shape* shape = new Rect(1,1,Color::RED,5,5);
	Shape* new_shape = shape->Clone();

	Shape* shape_1 = new Square(5,5,Color::GREEN, 10);
	Shape* shape_1_clone = shape_1->Clone();

	delete shape;
	delete new_shape;
	delete shape_1;
	delete shape_1_clone;
	return 0;
}