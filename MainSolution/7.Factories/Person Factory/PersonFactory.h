#ifndef _PERSON_FACTORY_H__
#define _PERSON_FACTORY_H__

#include "PersonBuilder.h"

class PersonFactory
{
	typedef const std::string& constStrRef;
private:
	PersonFactory() {
	
	}
public:
	~PersonFactory() = default;

public:

	static Person* create_person(constStrRef first_name, constStrRef last_name, constStrRef address, constStrRef cardNumber, int age) {
		return Person::create(ID_COUNTER++)
			.set_address(address)
			.set_age(age)
			.set_cardNumber(cardNumber)
			.set_firstName(first_name)
			.set_lastName(last_name)
			.build();
	}

private:
	static int ID_COUNTER;
};

int PersonFactory::ID_COUNTER = 0;

#endif // !_PERSON_FACTORY_H__
