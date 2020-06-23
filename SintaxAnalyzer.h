#pragma once
#include "StreamReader.h"
#include "LesAnalyzer.h"
#include "SymbolTab.h"
#include <list>
#include <string>
#include <map>

using namespace std;

class SintaxAnalyzer
{
	public:
		LesAnalyzer les;

		map<string, int> saved_words;
		map<string, int> saved_symbols;
		map<string, int> saved_types;

        string file_name;
        string path;

        list<char> buf;
        list<Token> tokens;
        list<Token> auxTokenList;
        int n_lines;

        void program() {
            string input;
            Token token;
            this->fill_saved_symbols();
            this->fill_saved_types();
            this->fill_saved_words();

            cout << "Digite o path: ";
            cin >> input;

            read(input);
            //for (char i : this->buf) { cout << i; }

            list<char>::iterator it = this->buf.begin();
            while (1){
                token = this->les.find_state(it, this->n_lines, this->saved_symbols, this->saved_words);
                cout << "Lexeme: " << token.lexeme << endl;
                this->tokens.push_back(token);

                if (!token.last) advance(it, 1);
                else {
                    break;
                }
            }
            this->eraseSubStr();
            this->streamWriterTAB();
            this->streamWriterLES();

        }

        void eraseSubStr(){
            string toErase = ".201";
            // Search for the substring in string
            size_t pos = this->file_name.find(toErase);
            if (pos != std::string::npos){
                // If found then erase it from string
                this->file_name.erase(pos, toErase.length());
            }
        }

        void streamWriterLES() {
            string extension = ".LEX";
            ofstream file(this->path + "\\" + this->file_name + extension);
            cout << this->path + "\\" + this->file_name + extension << endl;
            //printf("%s%s", &this->file_name, &this->path);
            //file.open(this->file_name+this->path);
            file << "Arquivo de relatório de análise léxica\n";
            file << "Equipe E02 - Magenta\n";
            file << "Integrantes:\n\n";
            file << "->Alfonso Carlos Paes Martinez Junior\t TEL: (71) 9 8180-0054\t EMAIL: engmartinez00@gmail.com\n";
            file << "->Lis da Silva Azevedo\t\t\t TEL: (71) 9 9214-2580\t EMAIL: lisazevedo3@gmail.com\n";
            file << "->Leonardo de Andrade Santana\t\t TEL: (71) 9 9407-5108\t EMAIL: devleonardoandrade@gmail.com\n";
            file << "->Daniel Campos Tavares Gomes\t\t TEL: (71) 9 9730-7988\t EMAIL: daniel.tavares.3096@gmail.com\n\n";
            file << "Lexeme\t| Id\t| IndiceTabelaSimbolos\n";
            file << "__________________________________________\n";
            int count = 0;

            for (Token& i : this->auxTokenList) {
                file << i.lexeme + " \t| " + to_string(i.token_id) + " \t| " + to_string(i.IdSymbolTab) + "\n";
                count++;
            }

            file.close();
        }

        void streamWriterTAB() {
            string extension = ".TAB";
            ofstream file(this->path + "\\" + this->file_name + extension);
            cout << this->path + "\\" + this->file_name + extension << endl;

            file << "Arquivo de relatório da tabela de símbolos\n";
            file << "Equipe E02 - Magenta\n\n";

            file << "Id\t| Lexeme\t| Código\t|  Tamanho antes de truncar\t| Tamanho depois de truncar\t| Linhas aparecidas\n\n";
            file << "___________________________________________________________________________________________________________\n";
            int count = 0;
            
            for (Token& i : this->tokens) {
                file << to_string(count) + " \t| " + i.lexeme + " \t| " + to_string(i.token_id) +"\t|" + to_string(i.exceeded_length) + "\t| " 
                    + to_string(i.length) +"\t| " + to_string(i.line_appearance.size()) +"\n";
                
                if (i.token_id != 0) {
                    i.IdSymbolTab = count;
                    auxTokenList.push_back(i);
                }
                count++;
            }
            file.close();

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

        bool is_c_valid(char c) {
            string s(1, c);
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

