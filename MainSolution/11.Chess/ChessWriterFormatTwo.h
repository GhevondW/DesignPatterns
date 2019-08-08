#pragma once
#include "ChessWriter.h"
class ChessWriterFormatTwo:public ChessWriter
{
public:
	ChessWriterFormatTwo(const string&);
	~ChessWriterFormatTwo();

	void accept_piece(const ChessPiece&)override;
	void close()override;

};

