#pragma once
#include <iostream>

using namespace std;
enum Color {
	Black,
	White,
	EmptyColor
};
enum Type {
	King,
	Queen,
	Rook,
	Bishop,
	Horse,
	Pawn,
	EmptyType
};


class ChessPiece
{
public:
	ChessPiece(int x, int y, Color color, Type type)
	:x(x),y(y),color(color),type(type){
		
	}
	~ChessPiece() {
	
	};

	int get_x()const {
		return x;
	}
	int get_y()const {
		return y;
	}
	Color get_color()const {
		return color;
	}
	Type get_type()const {
		return type;
	}
	
	void print()const  {
		cout << "x:" << x << " y:" << y << " c:" << color << " t:" << type << endl;
	}

private:
	int x;
	int y;
	Color color;
	Type type;
};

