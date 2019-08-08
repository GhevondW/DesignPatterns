#pragma once
#include <string>
#include "ChessPiece.h"

using namespace std;

class ChessReader
{
public:
	ChessReader(const string&);
	~ChessReader();

	virtual bool has_next() = 0;
	virtual ChessPiece get_next() = 0;

protected:
	string file_path;
};

