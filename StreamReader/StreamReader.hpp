
#pragma once

#include <string>
#include <list>

using namespace std;
 
class StreamReader  
{
	private:

	public:
		string file_name;
		string path;
		list<string> extensions;

		bool extension_validator(string file_name);
		bool path_validator(string file_name);
		void read(string file_name, string path);
		
		StreamReader();
		~StreamReader();

};