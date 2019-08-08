#pragma once
#include "ChessWriter.h"
class ChessWriterFormatOne:public ChessWriter
{
public:
	ChessWriterFormatOne(const string&);
	~ChessWriterFormatOne();

	void accept_piece(const ChessPiece&)override;
	void close()override;
private:
	char matrix[8][8];
	
};

