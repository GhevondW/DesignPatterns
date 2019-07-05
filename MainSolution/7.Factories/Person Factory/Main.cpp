#include <iostream>
#include "PersonFactory.h"

int main() {

	
	Person* Ghevond = Person::create()
		.set_address("Ayntap")
		.set_age(21)
		.set_cardNumber("5748-6900-0007-7895")
		.set_firstName("Ghevond")
		.set_lastName("Gevorgyan")
		.build();

	Person* Armen = Person::create()
		.set_address("Yerevan")
		.set_age(25)
		.set_cardNumber("5684")
		.set_firstName("Armen")
		.set_lastName("Kirakosyan")
		.build();

	Ghevond->print();
	Armen->print();

	Person* pers = PersonFactory::create_person("pers","pers","er","asdasdasd",45);

	pers->print();

	std::cin.get();
	return 0;
}