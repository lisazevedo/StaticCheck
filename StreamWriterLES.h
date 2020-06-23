#include "StreamWriter.h"
#include "Token.h"
#include <fstream>

using namespace std;

#pragma once
class StreamWriterLES: public StreamWriter
{
	list<Token> T;
public:
	StreamWriterLES(list<Token> T, string file_name, string path) {
		this->T = T;

		this->file_name = file_name;
		this->path = path;
		this->extension = ".LEX";
	}

	void write(string file_name, string path, list<Token> T) {
		
		
		string extension = ".LEX";
		ofstream file(file_name+extension);
		cout << file_name;
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
		for (Token& i : T) {
			file << i.lexeme + " \t| " + to_string(count) +" \t| " + to_string(i.token_id) +"\n";
			count++;
		}

		file.close();
	}
};

