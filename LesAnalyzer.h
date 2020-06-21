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
        enum Case { INITIAL, ALPHA, DIGIT, PARENTHESIS_OPEN, PARENTHESIS_CLOSE, 
            PLUS, HYPHEN, AMPERSAND, OLD_LADY_GAME, LES_THAN, BIGGER_THAN,
            EQUALS, EXCLAMATIONS, SEMI_COLON, COMMA, BRACKETS_OPEN, BRACKETS_CLOSE,
            CURLY_BRACKETS_OPEN, CURLY_BRACKETS_CLOSED, PERCENT, ASTERISK, PIPE,
            SLASH, UNDERSCORE
        };

        string word;
        Case state;
        int position;
        int DASH = 1;

        map<int, string> saved_words;
        map<int, string> saved_symbols;
        map<int, string> saved_types;
        //char current_position;

        Token find_state(list<char>::iterator &it, int *n_lines, string *error) {
            char ch;
         
            while (true) {

                ch = *it;

                switch (this->state){
                case INITIAL:
                    if (ch == ' ' || ch == '\t' || ch == '\r' ) {
                        this->state = INITIAL;
                        advance(it, this->DASH);
                        break;
                    }
                    else if (ch == '\n') {
                        this->state = INITIAL;
                        advance(it, this->DASH);
                        n_lines++;
                        break;
                    }
                    else if (isalpha(ch)) this->state = ALPHA;
                    else if (isdigit(ch)) this->state = DIGIT;
                    else if (ch == '(') this->state = PARENTHESIS_OPEN;
                    else if (ch == ')') this->state = PARENTHESIS_CLOSE;
                    else if (ch == '+') this->state = PLUS;
                    else if (ch == '-') this->state = HYPHEN;
                    else if (ch == '&') this->state = AMPERSAND;
                    else if (ch == '#') this->state = OLD_LADY_GAME;
                    else if (ch == '<') this->state = LES_THAN;
                    else if (ch == '>') this->state = BIGGER_THAN;
                    else if (ch == '=') this->state = EQUALS; 
                    else if (ch == '!') this->state = EXCLAMATIONS;
                    else if (ch == ';') this->state = SEMI_COLON; 
                    else if (ch == ',') this->state = COMMA; 
                    else if (ch == '[') this->state = BRACKETS_OPEN; 
                    else if (ch == ']') this->state = BRACKETS_CLOSE;
                    else if (ch == '{') this->state = CURLY_BRACKETS_OPEN; 
                    else if (ch == '}') this->state = CURLY_BRACKETS_CLOSED; 
                    else if (ch == '%') this->state = PERCENT;
                    else if (ch == '*') this->state = ASTERISK; 
                    else if (ch == '|') this->state = PIPE;
                    else if (ch == '/') this->state = SLASH;
                    else if (ch == '_') {
                        this->state = UNDERSCORE;
                        this->word += ch;
                        // contadorChar++;
                    }
                    else {
                        this->state = INITIAL;
                        advance(it, this->DASH);
                    }
                    break;

                case ALPHA:

                    break;

                case DIGIT:

                    break;

                case PARENTHESIS_OPEN:

                    break;

                case PARENTHESIS_CLOSE:

                    break;

                case PLUS:

                    break;

                case HYPHEN:

                    break;

                case AMPERSAND:

                    break;

                case OLD_LADY_GAME:

                    break;

                case LES_THAN:

                    break;

                case BIGGER_THAN:

                    break;

                case EQUALS:

                    break;

                case EXCLAMATIONS:

                    break;

                case SEMI_COLON:

                    break;

                case COMMA:

                    break;

                case BRACKETS_OPEN:

                    break;

                case BRACKETS_CLOSE:

                    break;

                case CURLY_BRACKETS_OPEN:

                    break;

                case CURLY_BRACKETS_CLOSED:

                    break;

                case PERCENT:

                    break;

                case ASTERISK:

                    break;

                case PIPE:

                    break;

                case SLASH:

                    break;

                case UNDERSCORE:

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

