#ifndef _SHAPE_H_
#define _SHAPE_H_

enum class Color {
	BLACK,
	RED,
	GREEN,
	BLUE
};

class Shape
{
public:
	virtual ~Shape() { std::cout << "Shape dtor." << std::endl; }
protected:
	Shape()
		:_x(0),
		_y(0),
		_color(Color::BLACK)
	{
		std::cout << "Shape ctor." << std::endl;
	}
	

	Shape(int x, int y, Color color)
		:_x(x),
		_y(y),
		_color(color)
	{
		std::cout << "Shape ctor." << std::endl;
	}

	Shape(const Shape& other) 
		:_x(other._x),
		_y(other._y),
		_color(other._color)
	{
		std::cout << "Shape Copy ctor." << std::endl;
	}


public:

	virtual Shape* Clone() const
	{
		return new Shape(*this);
	}

protected:
	int _x;
	int _y;
	Color _color;
};

class Rect : public Shape
{
public:
	Rect()
		:Shape(),
		_width(0),
		_height(0)
	{
		std::cout << "Rect ctor." << std::endl;
	}
	Rect(int x, int y, Color c, int w, int h)
		:Shape(x,y,c),
		_width(w),
		_height(h)
	{
		std::cout << "Rect ctor." << std::endl;
	}
	
	Rect(const Rect& other) 
		:Shape(other),
		_width(other._width),
		_height(other._height)
	{
		std::cout << "Rect Copy ctor." << std::endl;
	}

	~Rect() { std::cout << "Rect dtor." << std::endl; }

	Shape* Clone() const override
	{
		return new Rect(*this);
	}

private:
	int _width;
	int _height;
};

class Square : public Shape
{
public:
	Square()
		:Shape(),
		_size(0)
	{
		std::cout << "Square ctor." << std::endl;
	}
	Square(int x, int y, Color c, int size)
		:Shape(x, y, c),
		_size(size)
	{
		std::cout << "Square ctor." << std::endl;
	}

	Square(const Square& other)
		:Shape(other),
		_size(other._size)
	{
		std::cout << "Square Copy ctor." << std::endl;
	}

	~Square() { std::cout << "Square dtor." << std::endl; }

	Shape* Clone() const override
	{
		return new Square(*this);
	}

private:
	int _size;
};

#endif // !_SHAPE_H_

