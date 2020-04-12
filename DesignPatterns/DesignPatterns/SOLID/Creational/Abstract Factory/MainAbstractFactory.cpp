#if 0
#include <iostream>
#include "GUIFactory.h"

#define WINDOWS 1
#define MAC 0

int main()
{
	std::cout << "---Abstract Factory---" << std::endl;

	FactoryBase* factory = nullptr;

#if WINDOWS
	factory = new WindowsGUIFactory();
#elif MAC
	factory = new MacGUIFactory();
#else
	factory = nullptr;
#endif

	GUIButton* btn = factory->CreateButton();
	btn->OnDraw();
	btn->OnClick();
	btn->CallEvent();

	delete btn;
	btn = nullptr;

	GUICheckBox* check = factory->CreagteCheckBox();
	check->OnDraw();
	check->OnCheck();
	check->PrintStatus();

	delete check;
	check = nullptr;

	return 0;
}
#endif