#include "ChessReaderFormatTwo.h"
#include <string>


ChessReaderFormatTwo::ChessReaderFormatTwo(const string& file_path):ChessReader(file_path)
{
	file = ifstream(this->file_path);
}


ChessReaderFormatTwo::~ChessReaderFormatTwo()
{
	file.close();
}


bool ChessReaderFormatTwo::has_next() {
	current_piece = "";
	if (file.is_open()) {
		if (getline(file, current_piece)) {
			return true;
		}
	}
	return false;
}

ChessPiece ChessReaderFormatTwo::get_next() {
	char* piece_arr = new char[current_piece.length()];
	strcpy(piece_arr, current_piece.c_str());

	char type = piece_arr[0];
	char x = piece_arr[1];
	char y = piece_arr[2];

	Type t;
	Color c;

	switch (type)
	{
	case 'Q':
		t = Type::Queen;
		c = Color::White;
		break;
	case 'S':
		t = Type::Pawn;
		c = Color::White;
		break;
	case 'H':
		t = Type::Horse;
		c = Color::White;
		break;
	case 'K':
		t = Type::King;
		c = Color::White;
		break;
	case 'R':
		t = Type::Rook;
		c = Color::White;
		break;
	case 'B':
		t = Type::Bishop;
		c = Color::White;
		break;
	case 'q':
		t = Type::Queen;
		c = Color::Black;
		break;
	case 's':
		t = Type::Pawn;
		c = Color::Black;
		break;
	case 'h':
		t = Type::Horse;
		c = Color::Black;
		break;
	case 'k':
		t = Type::King;
		c = Color::Black;
		break;
	case 'r':
		t = Type::Rook;
		c = Color::Black;
		break;
	case 'b':
		t = Type::Bishop;
		c = Color::Black;
		break;
	default:
		t = Type::EmptyType;
		c = Color::EmptyColor;
		break;
	}

	return ChessPiece((int)(x - '0'),(int)(y - '0'),c,t);
}