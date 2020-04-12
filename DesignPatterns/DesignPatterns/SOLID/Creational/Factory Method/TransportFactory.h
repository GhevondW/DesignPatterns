#ifndef _TRANSPORT_FACTORY_H_
#define _TRANSPORT_FACTORY_H_

#include "Transport.h"

class TransportFactory
{
public:
	virtual Transport* CreateOne() = 0;
};

class CarFactory: public TransportFactory
{
public:
	Transport* CreateOne() override
	{
		return new Car{};
	}
};

class AirplaneFactory : public TransportFactory
{
public:
	Transport* CreateOne() override
	{
		return new Airplane{};
	}
};

#endif // !_TRANSPORT_FACTORY_H_

