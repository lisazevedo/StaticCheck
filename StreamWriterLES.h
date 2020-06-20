#include "StreamWriter.h"
#include "Token.h"
#include <fstream>

using namespace std;

#pragma once
class StreamWriterLES: public StreamWriter
{
	Token T;

	StreamWriterLES(Token T, string file_name, string path) {
		this->T = T;

		this->file_name = file_name;
		this->path = path;
		this->extension = ".LEX";
	}

	void write() {
		
		this->T;

		ofstream file;
		file.open(this->file_name+this->path);
		file << "Writing this to a file.\n";
		file.close();
	}
};

