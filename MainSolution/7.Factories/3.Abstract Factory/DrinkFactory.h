#ifndef _DRINK_FACTORY_H__
#define _DRINK_FACTORY_H__

#include "HotDrink.h"
#include "HotDrinkFactory.h"
#include <map>

class DrinkFactory
{
public:

	DrinkFactory() {
		_hot_drink_factories["coffee"] = std::make_unique<CoffeeFactory>();
		_hot_drink_factories["tea"] = std::make_unique<TeaFactory>();
	}

	std::unique_ptr<HotDrink> CreateHotDrink(const std::string& name) {
		auto result = _hot_drink_factories[name]->make();
		result->prepare(150);
		return result;
	}
private:
	 std::map<std::string, std::unique_ptr<HotDrinkFactory>> _hot_drink_factories;
};



#endif // !_DRINK_FACTORY_H__
