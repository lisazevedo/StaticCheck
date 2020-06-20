#include <list>

using namespace std;

#pragma once
class Token
{
	public:
		int token_id;
		int size;
		int appearance_qty;
		list<int> line_appearance;
		list<char> characteres;

		Token();
};

