#include "ChessWriterFormatOne.h"



ChessWriterFormatOne::ChessWriterFormatOne(const string& file_path):ChessWriter(file_path)
{
}


ChessWriterFormatOne::~ChessWriterFormatOne()
{
}




void ChessWriterFormatOne::accept_piece(const ChessPiece& chess_piece) {

	char result;

	if (chess_piece.get_color() == Color::Black) {
		switch (chess_piece.get_type())
		{
		case Type::Queen:
			result = 'q';
			break;
		case Type::Rook:
			result = 'r';
			break;
		case Type::Pawn:
			result = 's';
			break;
		case Type::King:
			result = 'k';
			break;
		case Type::Horse:
			result = 'h';
			break;
		case Type::EmptyType:
			result = '.';
			break;
		case Type::Bishop:
			result = 'b';
			break;
		default:
			break;
		}
	}
	else {
		switch (chess_piece.get_type())
		{
		case Type::Queen:
			result = 'Q';
			break;
		case Type::Rook:
			result = 'R';
			break;
		case Type::Pawn:
			result = 'S';
			break;
		case Type::King:
			result = 'K';
			break;
		case Type::Horse:
			result = 'H';
			break;
		case Type::EmptyType:
			result = '.';
			break;
		case Type::Bishop:
			result = 'B';
			break;
		default:
			break;
		}
	}
	matrix[chess_piece.get_y() - 1][chess_piece.get_x() - 1] = result;
}

void ChessWriterFormatOne::close() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			file << matrix[i][j];
		}
		file << endl;
	}
	file.close();
}