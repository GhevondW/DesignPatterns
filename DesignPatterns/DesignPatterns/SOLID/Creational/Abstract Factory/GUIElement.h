#ifndef _GUI_ELEMENT_H_
#define _GUI_ELEMENT_H_

#include <iostream>

class GUIElement
{
public:
	GUIElement() {}
	virtual ~GUIElement() {}

	virtual void OnDraw() = 0;

};

class GUIButton : public GUIElement
{
public:
	GUIButton() : GUIElement() {}
	virtual ~GUIButton() {}

	virtual void OnClick() = 0;
	virtual void CallEvent() = 0;
};

class GUICheckBox: public GUIElement
{
public:
	GUICheckBox() : GUIElement() {}
	virtual ~GUICheckBox() {}

	virtual void OnCheck() = 0;
	virtual void PrintStatus() = 0;

private:

};


class WindowsButton : public GUIButton
{
public:
	WindowsButton() : GUIButton() {}
	~WindowsButton() {}

	void OnDraw()
	{
		std::cout << "Windows Button OnDraw()" << std::endl;
	}

	void OnClick()
	{
		std::cout << "Windows Button OnClick()" << std::endl;
	}

	void CallEvent()
	{
		std::cout << "Windows Button CallEvent()" << std::endl;
	}

private:

};

class WindowsCheckBox : public GUICheckBox
{
public:
	WindowsCheckBox(): GUICheckBox()
	{
	
	}
	~WindowsCheckBox() {}

private:
	void OnDraw()
	{
		std::cout << "Windows CheckBox OnDraw()" << std::endl;
	}

	virtual void OnCheck()
	{
		std::cout << "Windows CheckBox OnCheck()" << std::endl;
	}

	virtual void PrintStatus()
	{
		std::cout << "Windows CheckBox PrintStatus()" << std::endl;
	}
};

class MacButton : public GUIButton
{
public:
	MacButton() : GUIButton() {}
	~MacButton() {}

	void OnDraw()
	{
		std::cout << "Mac Button OnDraw()" << std::endl;
	}

	void OnClick()
	{
		std::cout << "Mac Button OnClick()" << std::endl;
	}

	void CallEvent()
	{
		std::cout << "Mac Button CallEvent()" << std::endl;
	}

private:

};

class MacCheckBox : public GUICheckBox
{
public:
	MacCheckBox() : GUICheckBox()
	{

	}
	~MacCheckBox() {}

private:
	void OnDraw()
	{
		std::cout << "Mac CheckBox OnDraw()" << std::endl;
	}

	virtual void OnCheck()
	{
		std::cout << "Mac CheckBox OnCheck()" << std::endl;
	}

	virtual void PrintStatus()
	{
		std::cout << "Mac CheckBox PrintStatus()" << std::endl;
	}
};


#endif // !_GUI_ELEMENT_H_

