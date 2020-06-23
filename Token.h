#include <list>

using namespace std;

#pragma once
class Token
{
	public:
		int token_id;
		int length;
		int exceeded_length;
		int appearance_qty;
		list<int> line_appearance;
		char ch;
		bool last = false;
		string lexeme;
		int IdSymbolTab;

		

		//Token();
};

