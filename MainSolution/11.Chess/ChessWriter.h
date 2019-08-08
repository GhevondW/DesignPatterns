#pragma once
#include "ChessPiece.h"
#include <fstream>
class ChessWriter
{
public:
	ChessWriter(const string&);
	~ChessWriter();

	virtual void accept_piece(const ChessPiece&) = 0;
	virtual void close() = 0;
protected:
		ofstream file;
};

