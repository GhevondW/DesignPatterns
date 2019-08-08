#pragma once
#include "ChessReader.h"
class ChessReaderFormatThree:public ChessReader
{
public:
	ChessReaderFormatThree(const string& file_path);
	~ChessReaderFormatThree();

	bool has_next()override;
	ChessPiece get_next()override;
private:

	Type get_type_for_char(char);

	char* all_chars;
	int current_item;
	char table[8][8];

};

