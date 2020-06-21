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
		string file_name;
		string path;
		string extension = ".201";
		
		void read(string input) {

			get_file_name(input);
		

			if (!extension_validator()) {
				cout << "Not valid extension" << endl;
			}
			else {
				add_extension();
				char ch;

				ifstream file(this->path + "\\" + this->file_name, ios::in);

				if (file.is_open()) {
					cout << "Open file!!" << endl;
					while (file.good()) {
						file.get(ch);
					}
					file.close();
				}
				else {
					cout << "Unable to open file" << endl;
				}
			}

		}

	private:
		void get_file_name(const std::string& str) {

			size_t found = 0;
			found = str.find_last_of("/\\");

			if (found != 0) {
				this->path = str.substr(0, found);
			}
			else {
				size_t size = 10000;
				char* path = NULL;

				this->path = _getcwd(path, size);
			}
			this->file_name = str.substr(found + 1);
		}
	

		bool extension_validator() {
			
			if (this->file_name.find(".") == std::string::npos) {
				return true;
			}
			else {
				if (this->file_name.substr(this->file_name.find(".")) == this->extension) {
					return true;
				}
				else {
					return false;
				}
			}

			return false;
		}

		void add_extension() {

			if (this->file_name.find(this->extension) == std::string::npos) {
				this->file_name += this->extension;
			}
		}

		
};

