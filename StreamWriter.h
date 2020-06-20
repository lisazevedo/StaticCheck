#include <string>

using namespace std;

#pragma once
class StreamWriter
{
	public:
		string file_name;
		string path;
		string extension;

		string write(string file_name, string path);
};

