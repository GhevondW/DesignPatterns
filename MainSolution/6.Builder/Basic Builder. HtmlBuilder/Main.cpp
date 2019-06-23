#include <iostream>
#include "HtmlElemet.h"

int main() {

	HtmlElement result = HtmlElement::init("html")
		->add_child("h1", "text1")
		->add_child("h1", "text2")
		->add_child("h1", "text3")
		->add_child("h1", "text4")
		->build();

	std::cout << result.str() << std::endl;

	std::cin.get();
	return 0;
}