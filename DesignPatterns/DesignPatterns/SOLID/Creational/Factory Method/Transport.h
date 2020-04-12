#ifndef _TRANSPORT_H_
#define _TRANSPORT_H_

#include <iostream>

enum class Status
{
	ON_ROAD,
	REST,
	FINISH
};

class Transport
{
public:
	Transport() 
		:_eStatus(Status::REST)
	{}
	virtual ~Transport(){}

	virtual void Deliver() = 0;
	virtual void CheckStatus()
	{
		std::cout << (int)_eStatus << std::endl;
	}

protected:
	Status _eStatus;
};

class Car: public Transport
{
public:
	Car() :Transport(){}
	~Car() {}

	void Deliver() override
	{
		std::cout << "Delivering Car:" << std::endl;
		_eStatus = Status::ON_ROAD;
	}

private:
};

class Airplane : public Transport
{
public:
	Airplane() :Transport() {}
	~Airplane() {}

	void Deliver() override
	{
		std::cout << "Delivering Airplane:" << std::endl;
		_eStatus = Status::ON_ROAD;
	}

private:
};

#endif // !_TRANSPORT_H_

