#include <iostream>
#include <fstream>
#include <string>
#include <filesystem> 
#include <windows.h>
#include <direct.h>

using namespace std;

string EXTENSION = ".201";

string getCurrentPath(){
	size_t size=10000;
	char *path = NULL;
	
	path = _getcwd(path, size);

	return path;
}

string CURRENT_PATH = getCurrentPath() + "\\";

string add_extension(string name_file){
	
	if(name_file.find(EXTENSION) == std::string::npos){
		name_file += EXTENSION;		
	}
	name_file = CURRENT_PATH + name_file;
	
	return name_file;
}

void read_file(string name_file){ // http://www.cplusplus.com/doc/tutorial/files/
	
	string line;
	cout << "file name: " << add_extension(name_file) << endl;
	ifstream file(add_extension(name_file), ios::in);
	
  	if (file.is_open()){
  		
    	while (getline(file, line)){
      		cout << line << endl;
		}	
    	file.close();
  	}	
  	else{
		cout << "Unable to open file" << endl; 	
  	} 
}

int main(){
	
	return 0;
}
