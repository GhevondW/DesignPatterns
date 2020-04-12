#if 0
#include <iostream>
#include "JurnalPrinter.h"

int main() {

	std::cout << "---S---" << std::endl;

	Jurnal jurnal{ "Ghevond" };
	jurnal.Add("A1");
	jurnal.Add("A2");
	jurnal.Add("A3");
	jurnal.Add("A4");

	JurnalPrinter printer{&jurnal};

	printer.Print();

	return 0;
}
#endif