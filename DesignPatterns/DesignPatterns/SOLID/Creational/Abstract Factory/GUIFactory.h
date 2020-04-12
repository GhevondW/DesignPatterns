#ifndef _GUI_FACTORY_H_
#define _GUI_FACTORY_H_

#include "GUIElement.h"

class FactoryBase
{
public:
	virtual GUIButton* CreateButton() = 0;
	virtual GUICheckBox* CreagteCheckBox() = 0;
};

class WindowsGUIFactory: public FactoryBase
{
public:
	GUIButton* CreateButton() { return new WindowsButton(); }
	GUICheckBox* CreagteCheckBox() { return new WindowsCheckBox(); }
};

class MacGUIFactory : public FactoryBase
{
public:
	GUIButton* CreateButton() { return new MacButton(); }
	GUICheckBox* CreagteCheckBox() { return new MacCheckBox(); }
};

#endif // !_GUI_FACTORY_H_

