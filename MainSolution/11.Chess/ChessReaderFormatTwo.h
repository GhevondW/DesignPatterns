#pragma once
#include "ChessReader.h"
#include <fstream>
class ChessReaderFormatTwo:public ChessReader
{
public:
	ChessReaderFormatTwo(const string&);
	~ChessReaderFormatTwo();

	bool has_next()override;
	ChessPiece get_next()override;
protected:
	ifstream file;
	string current_piece;
};

