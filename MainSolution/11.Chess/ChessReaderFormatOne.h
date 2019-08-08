#pragma once
#include "ChessReader.h"
#include <fstream>

class ChessReaderFormatOne:public ChessReader
{
public:
	ChessReaderFormatOne(const string&);
	~ChessReaderFormatOne();

	bool has_next()override;
	ChessPiece get_next()override;
private:
	char* all_chars;
	int count;
	int current_item;
};

