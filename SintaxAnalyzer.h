#include "StreamReader.h"
#include "StreamWriter.h"
#include "LesAnalyzer.h"
#include "SymbolTab.h"
#include <string>
#include <map>

using namespace std;

#pragma once
class SintaxAnalyzer
{
	public:
		StreamReader file;
		StreamWriter writer_les;
		StreamWriter writer_sintax;
		LesAnalyzer les;

		map<int, string> saved_words;
		map<int, string> saved_symbols;
		map<string, string> saved_types;

		void save_tab() {

		}

		void call_les() {

		}
};

