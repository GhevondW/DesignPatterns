#include "Header.h"

int main() {

	Rectangle rect{3,4};
	Square sqr{5};

	process(rect);
	process(sqr);

	std::cin.get();
	return 0;
}