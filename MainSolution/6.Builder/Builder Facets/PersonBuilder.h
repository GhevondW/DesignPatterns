#ifndef _PERSON_BUILDER_H__
#define _PERSON_BUILDER_H__

#include "Person.h"

class PersonJobBuilder;
class PersonAddressBuilder;

class PersonBuilderBase
{
public:
	PersonBuilderBase(Person& person);

	PersonAddressBuilder lives() const;
	PersonJobBuilder works() const;

	operator Person() const{
		return std::move(_person);
	}

protected:
	Person& _person;
};


class PersonBuilder:public PersonBuilderBase
{
public:
	PersonBuilder();


private:
	Person _p;
};


#endif // !_PERSON_BUILDER_H__
