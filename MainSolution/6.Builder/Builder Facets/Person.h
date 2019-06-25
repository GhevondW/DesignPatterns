#ifndef _PERSON_H__
#define _PERSON_H__

#include <string>


class PersonBuilder;

class Person
{

private:

	std::string _street;
	std::string _post_code;
	std::string _city;
	std::string _company_name;
	std::string _position;
	int annual_incom{ 0 };

public:

	static PersonBuilder create();

	friend class PersonBuilder;
	friend class PersonAddressBuilder;
	friend class PersonJobBuilder;

};


#endif // !_PERSON_H__
