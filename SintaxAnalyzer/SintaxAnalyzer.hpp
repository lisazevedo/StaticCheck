
#pragma once
#include <map>
#include <string>

using namespace std; //acho q isso ta errado 

class SintaxAnalyzer  
{
	private:

	public:
		StreamReader file;
		StreamWriter writer_les;
		StreamWriter writer_sintax;
		LesAnalyzer les;

		map<int, string> saved_words;
		map<int, string> saved_symbols;
		map<string, string> saved_types;
		void save_tab();
		void call_les();
		
		SintaxAnalyzer();
		~SintaxAnalyzer();

};