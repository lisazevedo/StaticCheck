#include "StreamWriter.h"
#include "SymbolTab.h"

#pragma once
class StreamWriterTAB : public StreamWriter
{
	SymbolTab St;
	
	StreamWriterTAB(SymbolTab St, string file_name, string path) {
		this->St = St;
		
		this->file_name = file_name;
		this->path = path;
		this->extension = ".TAB";
	}

	void write() {
		this->St;

		ofstream file;
		file.open(this->file_name + this->path);
		
		file << "Writing this to a file.\n";
		
		file.close();
	}
};

