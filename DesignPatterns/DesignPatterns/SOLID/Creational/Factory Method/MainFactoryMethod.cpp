#if 0
#include <iostream>
#include "TransportFactory.h"

int main() {

	std::cout << "---Factory Method---" << std::endl;

	TransportFactory* factory = new CarFactory();
	Transport* car = factory->CreateOne();
	
	car->CheckStatus();
	car->Deliver();
	car->CheckStatus();

	delete factory;
	factory = new AirplaneFactory();
	Transport* airplane = factory->CreateOne();

	airplane->CheckStatus();
	airplane->Deliver();
	airplane->CheckStatus();


	delete car;
	delete airplane;
	delete factory;
	return 0;
}
#endif