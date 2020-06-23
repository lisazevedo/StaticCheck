#pragma once
#include <string>

using namespace std;

class StreamWriter
{
	public:
		string file_name;
		string path;
		string extension;

		
		void write();
};

