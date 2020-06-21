#include "StreamReader.h"
#include "StreamWriter.h"
#include "LesAnalyzer.h"
#include "SymbolTab.h"
#include <list>
#include <string>
#include <map>

using namespace std;

#pragma once
class SintaxAnalyzer
{
	public:
		StreamWriter writer_les;
		StreamWriter writer_sintax;
		LesAnalyzer les;

		map<int, string> saved_words;
		map<int, string> saved_symbols;
		map<int, string> saved_types;

        string file_name;
        string path;

        list<char> buf;

        int n_lines;

        void program(string input) {
            read(input);
            list<char>::iterator it = this->buf.begin();
            //while () {
            //    this->les.find_state(it);
            //}

        }

        void read(string input) { 

            this->file_name = StreamReader::get_file_name(input);
            this->path = StreamReader::get_path(input);

            if (!StreamReader::extension_validator(this->file_name)) {
                cout << "Not valid extension" << endl;
            }
            else {
                this->file_name = StreamReader::add_extension(this->file_name);
                char ch;

                ifstream file(this->path + "\\" + this->file_name, ios::in);

                if (file.is_open()) {
                    cout << "Open file!!" << endl;

                    while (file.good()) {
                        file.get(ch);
                        this->buf.push_back(toupper(ch));
                    }
                    file.close();
                }
                else {
                    cout << "Unable to open file" << endl;
                }
            }

        }
    private:
		void save_tab() {

		}

		void call_les() {

		}


        void fill_saved_words() {
            this->saved_words.insert(pair<int, string>(310, "BOOL"));
            this->saved_words.insert(pair<int, string>(311, "WHILE"));
            this->saved_words.insert(pair<int, string>(312, "BREAK"));
            this->saved_words.insert(pair<int, string>(313, "VOID"));
            this->saved_words.insert(pair<int, string>(314, "CHAR"));
            this->saved_words.insert(pair<int, string>(315, "TRUE"));
            this->saved_words.insert(pair<int, string>(316, "ELSE"));
            this->saved_words.insert(pair<int, string>(317, "STRING"));
            this->saved_words.insert(pair<int, string>(318, "END"));
            this->saved_words.insert(pair<int, string>(319, "RETURN"));
            this->saved_words.insert(pair<int, string>(320, "FALSE"));
            this->saved_words.insert(pair<int, string>(321, "PROGRAM"));
            this->saved_words.insert(pair<int, string>(322, "FLOAT"));
            this->saved_words.insert(pair<int, string>(323, "INT"));
            this->saved_words.insert(pair<int, string>(324, "IF"));
            this->saved_words.insert(pair<int, string>(325, "BEGIN"));

        }

        void fill_saved_symbols() {
            this->saved_symbols.insert(pair<int, string>(410, "!="));
            this->saved_symbols.insert(pair<int, string>(411, "#"));
            this->saved_symbols.insert(pair<int, string>(412, "&"));
            this->saved_symbols.insert(pair<int, string>(413, "("));
            this->saved_symbols.insert(pair<int, string>(414, "/"));
            this->saved_symbols.insert(pair<int, string>(415, ";"));
            this->saved_symbols.insert(pair<int, string>(416, "["));
            this->saved_symbols.insert(pair<int, string>(417, "{"));
            this->saved_symbols.insert(pair<int, string>(418, "+"));
            this->saved_symbols.insert(pair<int, string>(419, "<="));
            this->saved_symbols.insert(pair<int, string>(420, "="));
            this->saved_symbols.insert(pair<int, string>(421, ">="));
            this->saved_symbols.insert(pair<int, string>(422, "!"));
            this->saved_symbols.insert(pair<int, string>(423, "%"));
            this->saved_symbols.insert(pair<int, string>(424, ")"));
            this->saved_symbols.insert(pair<int, string>(425, "*"));
            this->saved_symbols.insert(pair<int, string>(426, ","));
            this->saved_symbols.insert(pair<int, string>(427, "]"));
            this->saved_symbols.insert(pair<int, string>(428, "|"));
            this->saved_symbols.insert(pair<int, string>(429, "}"));
            this->saved_symbols.insert(pair<int, string>(430, "<"));
            this->saved_symbols.insert(pair<int, string>(431, "=="));
            this->saved_symbols.insert(pair<int, string>(432, ">"));
            this->saved_symbols.insert(pair<int, string>(433, "-"));
        }

        void fill_saved_types() {
            this->saved_types.insert(pair<int, string>(510, "ch"));
            this->saved_types.insert(pair<int, string>(511, "CONSTANT-STRING"));
            this->saved_types.insert(pair<int, string>(512, "FLOAT-NUMBER"));
            this->saved_types.insert(pair<int, string>(513, "FUNCTION"));
            this->saved_types.insert(pair<int, string>(514, "IDENTIFIER"));
            this->saved_types.insert(pair<int, string>(515, "INTEGER-NUMBER"));
        }
};

