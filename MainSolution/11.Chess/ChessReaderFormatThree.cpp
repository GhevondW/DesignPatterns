#include "ChessReaderFormatThree.h"
#include <fstream>


ChessReaderFormatThree::ChessReaderFormatThree(const string& file_path)
	:ChessReader(file_path),current_item(0)
{
	ifstream file(this->file_path);
	if (file.is_open()) {
		string str;
		string result = "";
		while (getline(file, str)) {
			result += str;
		}
		
		all_chars = new char[result.length()];
		strcpy(all_chars, result.c_str());
		
	}
	file.close();
}


ChessReaderFormatThree::~ChessReaderFormatThree()
{
}


bool ChessReaderFormatThree::has_next() {
	if (current_item < 128) {
		return true;
	}
	return false;
}

Type ChessReaderFormatThree::get_type_for_char(char a) {
	Type t;
	switch (a)
	{
	case 'Q':
		t = Type::Queen;
		break;
	case 'S':
		t = Type::Pawn;
		break;
	case 'H':
		t = Type::Horse;
		break;
	case 'K':
		t = Type::King;
		break;
	case 'R':
		t = Type::Rook;
		break;
	case 'B':
		t = Type::Bishop;
		break;
	case 'q':
		t = Type::Queen;
		break;
	case 's':
		t = Type::Pawn;
		break;
	case 'h':
		t = Type::Horse;
		break;
	case 'k':
		t = Type::King;
		break;
	case 'r':
		t = Type::Rook;
		break;
	case 'b':
		t = Type::Bishop;
		break;
	default:
		t = Type::EmptyType;
		break;
	}
	return t;
}

ChessPiece ChessReaderFormatThree::get_next() {
	char current_char = all_chars[current_item];

	int x, y;
	Color c;
	Type t;

	if (current_item < 64) {
		c = Color::White;
		if ((current_item + 1) % 8 == 0) {
			x = 8;
		}
		else {
			x = (current_item + 1) % 8;
		}

		y = current_item / 8 + 1;
	}
	else {
		c = Color::Black;
		if ((current_item + 1 - 64) % 8 == 0) {
			x = 8;
		}
		else {
			x = (current_item + 1 - 64) % 8;
		}

		y = (current_item - 64)/ 8 + 1;
	}

	t = get_type_for_char(current_char);

	current_item++;

	if (table[x-1][y-1] == '.' || table[x - 1][y - 1] == '\0') {
		table[x - 1][y - 1] = current_char;
		return ChessPiece(x, y, c, t);
	}
	else {
		Type t = get_type_for_char(table[x - 1][y - 1]);
		return ChessPiece(x, y, Color::White, t);
	}

}