#pragma once
#include "StreamReader.h"
#include "StreamWriter.h"
#include "LesAnalyzer.h"
#include "SymbolTab.h"
#include <list>
#include <string>
#include <map>

using namespace std;

class SintaxAnalyzer
{
	public:
		StreamWriter writer_les;
		StreamWriter writer_sintax;
		LesAnalyzer les;

		map<string, int> saved_words;
		map<string, int> saved_symbols;
		map<string, int> saved_types;

        string file_name;
        string path;

        list<char> buf;

        int n_lines;

        void program() {
            string input = "A:\\Repo\\testes\\test2";
            Token token;
            this->fill_saved_symbols();
            this->fill_saved_types();
            this->fill_saved_words();

            cout << "Digite o path: ";
            //cin >> input;

            read(input);
            for (char i : this->buf) { cout << i; }

            list<char>::iterator it = this->buf.begin();
            while (*it != '@'){
                token = this->les.find_state(it, this->n_lines, this->saved_symbols, this->saved_words);
                cout << "Lexeme: " << token.lexeme << endl;
            }
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

                    while (file.get(ch)) {
                        
                        if (is_c_valid(ch)) {
                            this->buf.push_back(toupper(ch));
                        }
                    }
                    this->buf.push_back('@');
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

        bool is_c_valid(char c) {
            string s(1, c);
            cout << this->les.find_token(saved_symbols, s) << endl;
            if (this->les.find_token(saved_symbols, s) != 0 || isalpha(c) || isdigit(c) || c == ' ' || c == '\t' || c == '\r' || c == '\n') return true;
            return false;
        }

        void fill_saved_words() {
            this->saved_words.insert(pair<string, int>("BOOL",310));
            this->saved_words.insert(pair<string, int>("WHILE", 311));
            this->saved_words.insert(pair<string, int>("BREAK", 312));
            this->saved_words.insert(pair<string, int>("VOID", 313));
            this->saved_words.insert(pair<string, int>("CHAR", 314));
            this->saved_words.insert(pair<string, int>("TRUE", 315));
            this->saved_words.insert(pair<string, int>("ELSE", 316));
            this->saved_words.insert(pair<string, int>("STRING", 317));
            this->saved_words.insert(pair<string, int>("END", 318));
            this->saved_words.insert(pair<string, int>("RETURN", 319));
            this->saved_words.insert(pair<string, int>("FALSE", 320));
            this->saved_words.insert(pair<string, int>("PROGRAM", 321));
            this->saved_words.insert(pair<string, int>("FLOAT", 322));
            this->saved_words.insert(pair<string, int>("INT", 323));
            this->saved_words.insert(pair<string, int>("IF", 324));
            this->saved_words.insert(pair<string, int>("BEGIN", 325));
        }

        void fill_saved_symbols() {
            this->saved_symbols.insert(pair<string, int>("!=", 410));
            this->saved_symbols.insert(pair<string, int>("#", 411));
            this->saved_symbols.insert(pair<string, int>("&", 412));
            this->saved_symbols.insert(pair<string, int>("(", 413));
            this->saved_symbols.insert(pair<string, int>("/", 414));
            this->saved_symbols.insert(pair<string, int>(";", 415));
            this->saved_symbols.insert(pair<string, int>("[", 416));
            this->saved_symbols.insert(pair<string, int>("{", 417));
            this->saved_symbols.insert(pair<string, int>("+", 418));
            this->saved_symbols.insert(pair<string, int>("<=", 419));
            this->saved_symbols.insert(pair<string, int>("=", 420));
            this->saved_symbols.insert(pair<string, int>(">=", 421));
            this->saved_symbols.insert(pair<string, int>("!", 422));
            this->saved_symbols.insert(pair<string, int>("%", 423));
            this->saved_symbols.insert(pair<string, int>(")", 424));
            this->saved_symbols.insert(pair<string, int>("*", 425));
            this->saved_symbols.insert(pair<string, int>(",", 426));
            this->saved_symbols.insert(pair<string, int>("]", 427));
            this->saved_symbols.insert(pair<string, int>("|", 428));
            this->saved_symbols.insert(pair<string, int>("}", 429));
            this->saved_symbols.insert(pair<string, int>("<", 430));
            this->saved_symbols.insert(pair<string, int>("==", 431));
            this->saved_symbols.insert(pair<string, int>(">", 432));
            this->saved_symbols.insert(pair<string, int>("-", 433));
        }

        void fill_saved_types() {
            this->saved_types.insert(pair<string, int>("ch", 510));
            this->saved_types.insert(pair<string, int>("CONSTANT-STRING", 511));
            this->saved_types.insert(pair<string, int>("FLOAT-NUMBER", 512));
            this->saved_types.insert(pair<string, int>("FUNCTION", 513));
            this->saved_types.insert(pair<string, int>("IDENTIFIER", 514));
            this->saved_types.insert(pair<string, int>("INTEGER-NUMBER", 515));
        }
};

