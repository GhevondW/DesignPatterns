#ifndef _HOT_DRINK_FACTORY_H__
#define _HOT_DRINK_FACTORY_H__

#include "HotDrink.h"


class HotDrinkFactory //Abstract Factory
{
public:
	virtual std::unique_ptr<HotDrink> make()const= 0;
};

class TeaFactory :public HotDrinkFactory{
public:
	std::unique_ptr<HotDrink> make() const override{
		return std::make_unique<Tea>();
	}
};

class CoffeeFactory :public HotDrinkFactory {
public:
	std::unique_ptr<HotDrink> make() const override {
		return std::make_unique<Coffee>();
	}
};

#endif // !_HOT_DRINK_FACTORY_H__
