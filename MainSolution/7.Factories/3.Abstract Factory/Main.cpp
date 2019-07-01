#include <iostream>
#include "DrinkFactory.h"


enum HotDrinkType
{
	COFFEE,
	TEA
};


std::unique_ptr<HotDrink> CreateHotDrink(HotDrinkType type) {
	std::unique_ptr<HotDrinkFactory> factory(new CoffeeFactory());
	if (type == HotDrinkType::TEA) {
		factory.reset(new TeaFactory());
	}
	return factory->make();
}

int main() {

	CreateHotDrink(HotDrinkType::TEA)->prepare(15);

	auto result = DrinkFactory().CreateHotDrink("coffee");

	std::cin.get();
	return 0;
}