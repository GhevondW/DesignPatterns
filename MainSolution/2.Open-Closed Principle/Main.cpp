#include "Header.h"

int main() {

	Product apple1{"Apple1",Color::RED,Size::LARGE};
	Product apple2{"Apple2",Color::GREEN,Size::LARGE};
	Product orange{"Orange",Color::ORANGE,Size::MEDIUM};

	ColorSpecification colorSpec(Color::RED);
	ColorAndSizeSpecialization colorAndSizeSpec(Color::GREEN,Size::LARGE);
	std::vector<Product> vect = { apple1,apple2,orange};
	
	GoodFilter filter;

	auto result = filter.filter(vect,colorSpec);
	result = filter.filter(vect,colorAndSizeSpec);

	AndSpecification aspec{&colorSpec, &colorAndSizeSpec};

	std::cin.get();
	return 0;
}