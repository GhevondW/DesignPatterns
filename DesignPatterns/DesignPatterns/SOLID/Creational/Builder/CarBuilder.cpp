#include "Car.h"

CarBuilder::CarBuilder()
	:_pCar(nullptr)
{
	std::cout << "Builder Ctor" << std::endl;
	_pCar = new Car{};
}

CarBuilder::~CarBuilder() 
{
	std::cout << "Builder Dtor" << std::endl;
}

IBuilder& CarBuilder::SetClass(const CarClass cl)
{
	_pCar->_eClass = cl;
	return *this;
}
IBuilder& CarBuilder::SetColor(const Color color)
{
	_pCar->_eColor = color;
	return *this;
}
IBuilder& CarBuilder::SetStage(const Stage stage)
{
	_pCar->_eStage = stage;
	return *this;
}
IBuilder& CarBuilder::SetDoorsCount(const int count) 
{
	_pCar->_iDoors = count;
	return *this;
}
IBuilder& CarBuilder::SetHp(const int val) 
{
	_pCar->_iHp = val;
	return *this;
}
IBuilder& CarBuilder::SetNm(const int val) 
{
	_pCar->_iNm = val;
	return *this;
}
IBuilder& CarBuilder::SetGPS(const bool val)
{
	_pCar->_bGPS = val;
	return *this;
}
IBuilder& CarBuilder::SetChip(const bool val)
{
	_pCar->_bChip = val;
	return *this;
}
IBuilder& CarBuilder::SetAI(const bool val)
{
	_pCar->_bAudiAI = val;
	return *this;
}
Car* CarBuilder::Build()
{
	return _pCar;
}

