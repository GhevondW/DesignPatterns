#ifndef _PERSON_BUILDER_H__
#define _PERSON_BUILDER_H__

#include <string>
#include <iostream>

class PersonBuilder;

class Person
{
	friend class PersonBuilder;
private:
	Person(const int id)
		:_id(id)
	{}
public:
	~Person() {}

public:

	int get_id() const {
		return _id;
	}

	const std::string& get_firstName() const {
		return _firstName;
	}

	const std::string& get_lastName() const {
		return _lastName;
	}

	const std::string& get_address() const {
		return _address;
	}

	const std::string& get_cardNumber()const {
		return _cardNumber;
	}

	int get_age()const {
		return _age;
	}

private:

	void set_firstName(const std::string& firstName) {
		_firstName = firstName;
	}

	void set_lastName(const std::string& lastName) {
		_lastName = lastName;
	}

	void set_address(const std::string& address) {
		_address = address;
	}

	void set_cardNumber(const std::string& cardNumber) {
		_cardNumber = cardNumber;
	}


public:

	void set_age(const int age) {
		_age = age;
	}

	void print()const {
		std::cout << "----------------------------------------------------------------------------------" << std::endl;
		std::cout << "id:" << _id << std::endl;
		std::cout << "first name:" <<_firstName << std::endl;
		std::cout << "last name:" << _lastName << std::endl;
		std::cout << "address:" << _address << std::endl;
		std::cout << "card number:" << _cardNumber << std::endl;
		std::cout << "age:" << _age << std::endl;
		std::cout << "----------------------------------------------------------------------------------" << std::endl;
	}

public:

	static PersonBuilder create();

private:
	const int _id;
	std::string _firstName;
	std::string _lastName;
	std::string _address;
	std::string _cardNumber;
	int _age{};
};


class PersonBuilderBase
{
public:
	PersonBuilderBase(Person* person)
		:_person(person),
		_local_counter(0)
	{}
	~PersonBuilderBase() {};

	Person* build() {
		if (_local_counter >= 5) {
			return _person;
		}
		throw "invalid Person object Created";
	}

protected:
	Person* _person;
	static int ID_COUNTER;
	int _local_counter;
};

int PersonBuilderBase::ID_COUNTER = 0;

class PersonBuilder :public PersonBuilderBase
{
	friend class Person;
private:
	PersonBuilder() :
		_pers(new Person(PersonBuilderBase::ID_COUNTER++)),
		PersonBuilderBase(_pers)
	{

	}
public:
	~PersonBuilder() = default;

	PersonBuilder& set_firstName(const std::string& firstName) {
		_person->set_firstName(firstName);
		_local_counter++;
		return *this;
	}

	PersonBuilder& set_lastName(const std::string& lastName) {
		_person->set_lastName(lastName);
		_local_counter++;
		return *this;
	}

	PersonBuilder& set_address(const std::string& address) {
		_person->set_address(address);
		_local_counter++;
		return *this;
	}

	PersonBuilder& set_age(const int age) {
		_person->set_age(age);
		_local_counter++;
		return *this;
	}

	PersonBuilder& set_cardNumber(const std::string& cardNumber) {
		_person->set_cardNumber(cardNumber);
		_local_counter++;
		return *this;
	}

private:
	Person* _pers;
};

PersonBuilder Person::create() {
	return PersonBuilder();
}

#endif // !_PERSON_BUILDER_H__
