#ifndef _HOT_DRINK_H__
#define _HOT_DRINK_H__

#include <iostream>
#include <memory>

class HotDrink
{
public:
	virtual ~HotDrink() = default;
	virtual void prepare(int volume) = 0;
};
 // !_HOT_DRINK_H__

class Tea:public HotDrink
{
public:
	void prepare(int volume) override {
		std::cout << "this is the [Tea] class prepare function, Volume:"<<volume<< std::endl;
	}
};

class Coffee :public HotDrink
{
public:
	void prepare(int volume) override {
		std::cout << "this is the [Coffee] class prepare function, Volume:" << volume << std::endl;
	}
};

#endif