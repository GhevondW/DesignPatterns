#include <iostream>
#include "Person.h"
#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

int main() {

	Person p = Person::create()
		.works()
		.at("imagenomic")
		.as_a("c++ developer")
		.lives()
		.at("Ayntap")
		.in("1/33")
		.with_postcode("0803");

	std::cin.get();
	return 0;
}