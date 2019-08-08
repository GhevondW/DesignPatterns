#pragma once
#include "ChessWriter.h"
class ChessWriterFormatThree:public ChessWriter
{
public:
	ChessWriterFormatThree(const string&);
	~ChessWriterFormatThree();

	void accept_piece(const ChessPiece&)override;
	void close()override;
private:
	char white_matrix[8][8];
	char black_matrix[8][8];
};

