#include <memory>
#include "Jurnal.h"

int main() {

	std::unique_ptr<Jurnal> jurnal(new Jurnal("Ghevond's Jurnal"));
	

	jurnal.get()->add_entry("first");
	jurnal.get()->add_entry("second");
	jurnal.get()->add_entry("third");

	JurnalsManager::print(*jurnal.get());

	std::cin.get();
	return 0;
}
