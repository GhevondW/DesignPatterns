#if 0
#include <iostream>
#include "Car.h"

int main()
{
	std::cout << "---Builder---" << std::endl;

	Car* car = Car::Make()
		.SetAI(true)
		.SetChip(true)
		.SetColor(Color::BLACK)
		.SetClass(CarClass::RS6)
		.SetHp(1000)
		.SetNm(1250)
		.SetGPS(true)
		.SetStage(Stage::STAGE2)
		.SetDoorsCount(5)
		.Build();


	delete car;
	return 0;
}
#endif