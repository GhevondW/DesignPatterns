#include "ChessWriterFormatTwo.h"
#include <sstream>


ChessWriterFormatTwo::ChessWriterFormatTwo(const string& file_path)
	:ChessWriter(file_path)
{

}


ChessWriterFormatTwo::~ChessWriterFormatTwo(){
}


void ChessWriterFormatTwo::accept_piece(const ChessPiece& chess_piece) {
	string result = "";

	if (chess_piece.get_color() == Color::Black) {
		switch (chess_piece.get_type())
		{
		case Type::Queen:
			result += "q";
			break;
		case Type::Rook:
			result += "r";
			break;
		case Type::Pawn:
			result += "s";
			break;
		case Type::King:
			result += "k";
			break;
		case Type::Horse:
			result += "h";
			break;
		case Type::EmptyType:
			result += ".";
			break;
		case Type::Bishop:
			result += 'b';
			break;
		default:
			break;
		}
	}
	else {
		switch (chess_piece.get_type())
		{
		case Type::Queen:
			result += "Q";
			break;
		case Type::Rook:
			result += "R";
			break;
		case Type::Pawn:
			result += "S";
			break;
		case Type::King:
			result += "K";
			break;
		case Type::Horse:
			result += "H";
			break;
		case Type::EmptyType:
			result += ".";
			break;
		case Type::Bishop:
			result += 'B';
			break;
		default:
			break;
		}
	}

	ostringstream convert;
	convert << chess_piece.get_x() << chess_piece.get_y();
	result += convert.str();
	
	

	char* str = new char[result.length()];
	strcpy(str, result.c_str());

	file << str << endl;
	
}

void ChessWriterFormatTwo::close() {
	file.close();
}