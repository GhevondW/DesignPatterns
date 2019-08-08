#include <iostream>
#include "ChessReaderFormatOne.h"
#include "ChessWriterFormatTwo.h"
#include "ChessReaderFormatTwo.h"
#include "ChessWriterFormatOne.h"
#include "ChessReaderFormatThree.h"
#include "ChessWriterFormatThree.h"

using namespace std;

void convert(ChessReader* reader,
	ChessWriter* writer) {
	while (reader->has_next()) {
		writer->accept_piece(reader->get_next());
	}
	
	writer->close();
}

int main() {
	

	int format_in = 1, format_out = 2;
	string file_in = "input1.txt";
	string file_out = "output2.txt";
	ChessReader* reader;

	if (format_in == 1) {
		reader = new ChessReaderFormatOne(file_in);
	}
	else if (format_in == 2) {
		reader = new ChessReaderFormatTwo(file_in);
	}
	else{
		reader = new ChessReaderFormatThree(file_in);
	}
	
	ChessWriter* writer;

	if (format_out == 1) {
		writer = new ChessWriterFormatOne(file_out);
	}
	else if (format_out == 2) {
		writer = new ChessWriterFormatTwo(file_out);
	}
	else{
		writer = new ChessWriterFormatThree(file_out);
	}

	convert(reader, writer);

	delete reader;
	delete writer;
	
	return 0;
}