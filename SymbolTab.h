#include <string>
#include <list>

using namespace std;
#pragma once
class SymbolTab
{
	public:	
		string type;
		string lexeme;
		string symbol;
		
		int token_id;
		int code;
		int before_trucate;
		int after_trucate;
		int symbol_id;

		list<int>initial_lines;
		
		SymbolTab();
};

