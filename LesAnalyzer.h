#include "Token.h"
#include <map>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

#pragma once
class LesAnalyzer
{

    public:
        Token T;


        string word;
        int state;
        int position;
        int DASH = 1;

        map<int, string> saved_words;
        map<int, string> saved_symbols;
        map<int, string> saved_types;
        //char current_position;

        Token find_state(list<char>::iterator &it, int *n_lines) {
            char ch;
         

            while (true) {

                ch = *it;

                switch (this->state){
                case 0:
                    if (ch == ' ' || ch == '\t' || ch == '\r' ) {
                        this->state = 0;
                        advance(it, this->DASH);
                        break;
                    }
                    else if (ch == '\n') {
                        this->state = 0;
                        advance(it, this->DASH);
                        n_lines++;
                        break;
                    }
                    else if (isalpha(ch)) {
                        this->state = 1;
                    }
                    else if () {
                        
                    }
                    break;
                case 1:

                    break;
                default:
                    break;
                }

                
            }

                
            
            //return this->T;
        }

    private:

        void token_clear() {
            this->word.clear();

            this->T.token_id = 0;
            //this->T.length = 0;
            //this->T.exceeded_length = 0;
            this->T.lexeme.clear();
            this->T.appearance_qty = 0;
            this->T.line_appearance.clear();
            this->T.ch = ' ';
        }

        void check_token_length() {

            if (this->word.length() >= 30) {

                this->T.length = 30;
                this->T.exceeded_length = this->word.length();
                this->T.lexeme = this->word.substr(0, 30);

                cout << this->T.lexeme.length() << endl << this->T.lexeme << endl; //TEST
            }
            else {
                this->T.length = word.length();
                this->T.exceeded_length = 0;
            }
        }

 

    //LesAnalyzer();
    //~LesAnalyzer();
};

