#include <iostream>
#include <fstream>
#include <string>
//#include <filesystem> 
//#include <windows.h>
#include <direct.h>
#include <list>

using namespace std;

#pragma once
class StreamReader
{
	public:
		
		static string get_file_name(const std::string& str) {

			size_t found = 0;
			found = str.find_last_of("/\\");

			string file_name = str.substr(found + 1);

			return file_name;
		}
		
		static string get_path(const std::string& str) {
			string path;

			size_t found = 0;
			found = str.find_last_of("/\\");

			if (found != 0) {
				return path = str.substr(0, found);
			}
			else {
				size_t size = 10000;
				char* path = NULL;

				return path = _getcwd(path, size);
			}

		}

		static bool extension_validator(string file_name) {
			
			string extension = ".201";

			if (file_name.find(".") == std::string::npos) {
				return true;
			}
			else {
				if (file_name.substr(file_name.find(".")) == extension) {
					return true;
				}
				else {
					return false;
				}
			}

			return false;
		}

		static string add_extension(string file_name) {
			string extension = ".201";

			if (file_name.find(extension) == std::string::npos) {
				file_name += extension;
			}

			return file_name;
		}

		
};

