#pragma once
class SymbolTab
{
	public:	
		int token_id;
		string type;
		string lexeme;
		int code;
		int before_trucate;
		int after_trucate;
		list<int>initial_lines;
		string symbol;
		int symbol_id;

		SymbolTab();
};

