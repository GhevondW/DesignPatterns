#include "ChessWriter.h"



ChessWriter::ChessWriter(const string& file_path)
{
	file.open(file_path);
}


ChessWriter::~ChessWriter()
{
	
}
