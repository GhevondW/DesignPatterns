#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonBuilderBase::PersonBuilderBase(Person& person) 
	:_person(person)
{

}

PersonBuilder::PersonBuilder()
	:PersonBuilderBase(_p)
{

}

PersonAddressBuilder PersonBuilderBase::lives() const {
	return PersonAddressBuilder{ _person };
}
PersonJobBuilder PersonBuilderBase::works() const {
	return PersonJobBuilder{ _person };
}