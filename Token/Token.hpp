#pragma once

#include <list>
using namespace std;


class Token  
{
	private:

	public:
		int token_id;
		int size;
		int appearance_qty;
		list<int> line_appearance;
		list<char> characteres;
		
		Token();
};