#ifndef _HEADER_H__
#define _HEADER_H__

#include <iostream>

/**
* This example shows that Square is not Rectangle
* and we should not create inheritance betweene them
*/
class Rectangle
{
public:
	Rectangle(int width,int height) 
		:_width(width),
		_height(height){}
	~Rectangle() {}
public:

	int get_width() const{
		return _width;
	}

	int get_height()const {
		return _height;
	}

	virtual void set_width(int width) {
		_width = width;
	}

	virtual void set_height(int height) {
		_height = height;
	}

public:

	int get_area() const{
		return _width * _height;
	}

protected:
	int _width;
	int _height;
};

class Square:public Rectangle
{
public:
	Square(int size) 
		:Rectangle(size,size){}
	~Square(){}
private:
	void set_width(int width) override{
		_width = _height = width;
	}
	void set_height(int height) override{
		_height = _width = height;
	}
};


void process(Rectangle& rect) {

	int width = rect.get_width();
	rect.set_height(10);
	std::cout << "Expect:[" << width * 10 << "] and get:[" << rect.get_area()<<"]"<< std::endl;
}

#endif // !_HEADER_H__
