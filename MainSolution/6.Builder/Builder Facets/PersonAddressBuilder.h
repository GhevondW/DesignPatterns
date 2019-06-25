#ifndef _PERSON_ADDRESS_BUILDER_H__
#define _PERSON_ADDRESS_BUILDER_H__

#include <string>

class PersonAddressBuilder:public PersonBuilderBase
{
	typedef PersonAddressBuilder self;
public:
	PersonAddressBuilder(Person& person):PersonBuilderBase(person) {}

	self& at(const std::string& street_address) {
		_person._street = street_address;
		return *this;
	}
	self& with_postcode(const std::string& postcode) {
		_person._post_code = postcode;
		return *this;
	}
	self& in(const std::string& city) {
		_person._city = city;
		return *this;
	}
};

#endif // !_PERSON_ADDRESS_BUILDER_H__
