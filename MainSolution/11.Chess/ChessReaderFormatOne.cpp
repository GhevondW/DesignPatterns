#include "ChessReaderFormatOne.h"



ChessReaderFormatOne::ChessReaderFormatOne(const string& file_path)
	:ChessReader(file_path),current_item(0)
{
	ifstream file(this->file_path);
	if (file.is_open()) {
		string str;
		string result = "";
		while (getline(file, str)) {
			result += str;
		}
		count = result.length() - 1;
		all_chars = new char[count];
		strcpy(all_chars, result.c_str());
	}
	file.close();
}


ChessReaderFormatOne::~ChessReaderFormatOne()
{
}

bool ChessReaderFormatOne::has_next() {
	if (current_item <= count) {
		return true;
	}
	return false;
}

ChessPiece ChessReaderFormatOne::get_next() {
	char a = all_chars[current_item];
	
	Type t = Type::EmptyType;
	Color c = Color::EmptyColor;

	if (a == 'K') {
		t = Type::King;
		c = Color::White;
	}
	else if (a == 'Q') {
		t = Type::Queen;
		c = Color::White;
	}
	else if (a == 'R') {
		t = Type::Rook;
		c = Color::White;
	}
	else if (a == 'B') {
		t = Type::Bishop;
		c = Color::White;
	}
	else if (a == 'H') {
		t = Type::Horse;
		c = Color::White;
	}
	else if (a == 'S') {
		t = Type::Pawn;
		c = Color::White;
	}
	else if (a == 'k') {
		t = Type::King;
		c = Color::Black;
	}
	else if (a == 'q') {
		t = Type::Queen;
		c = Color::Black;
	}
	else if (a == 'r') {
		t = Type::Rook;
		c = Color::Black;
	}
	else if (a == 'b') {
		t = Type::Bishop;
		c = Color::Black;
	}
	else if (a == 'h') {
		t = Type::Horse;
		c = Color::Black;
	}
	else if (a == 's') {
		t = Type::Pawn;
		c = Color::Black;
	}

	int x, y;
	if ((current_item + 1)%8 == 0) {
		x = 8;
	}
	else {
		x = (current_item + 1) % 8;
	}
	
	y = current_item/8 + 1;

	current_item++;
	
	return ChessPiece(x, y, c, t);
}