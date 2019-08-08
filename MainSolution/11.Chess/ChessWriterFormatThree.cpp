#include "ChessWriterFormatThree.h"



ChessWriterFormatThree::ChessWriterFormatThree(const string& file_path):ChessWriter(file_path)
{
}


ChessWriterFormatThree::~ChessWriterFormatThree()
{
}

void ChessWriterFormatThree::accept_piece(const ChessPiece& chess_piece) {

	char result;

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

	if (chess_piece.get_color() == Color::White) {
		white_matrix[chess_piece.get_y() - 1][chess_piece.get_x() - 1] = result;
	}
	else if(chess_piece.get_color() == Color::Black) {
		black_matrix[chess_piece.get_y() - 1][chess_piece.get_x() - 1] = result;
	}

}

void ChessWriterFormatThree::close() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			file << white_matrix[i][j];
		}
		file << endl;
	}
	file << endl;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			file << black_matrix[i][j];
		}
		file << endl;
	}
	file.close();
}