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
            EQUAL, EXCLAMATION, SEMI_COLON, COMMA, BRACKETS_OPEN, BRACKETS_CLOSE,
            CURLY_BRACKETS_OPEN, CURLY_BRACKETS_CLOSED, PERCENT, ASTERISK, PIPE,
            SLASH, UNDERSCORE
        };

        string word;
        Case state;
        int position;
        int DASH = 1;

        //char current_position;

        Token find_state(list<char>::iterator &it, int *n_lines, map<int, string> *saved_symbols) {
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
                    else if (ch == '=') this->state = EQUAL; 
                    else if (ch == '!') this->state = EXCLAMATION;
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
                    this->word += ch;
                    advance(it, this->DASH);
                    char nxt_ch = this->peek(it);

                    // Formação de letra com hífen
                    if (nxt_ch == '-') this->state = ALPHA_HYPHEN;

                    // Quebra de linha
                    else if (nxt_ch == '\n') {
                        n_lines++;
                        advance(it, this->DASH);
                    }
                    break;

                case DIGIT:
                    this->word += ch;
                    char nxt_ch = this->peek(it);

                    // Formação de float
                    if (nxt_ch == '.') this->state = DIGIT_FLOAT;
                    if (!isdigit(nxt_ch) && nxt_ch != '.' && this->state != DIGIT_FLOAT) this->DIGIT_INT;
                    // Essa parte ta diferente do deles, não entendi o pq do que eles tavam fazendo
                    if (nxt_ch == '\n') {
                        n_lines++;
                        advance(it, this->DASH);
                    }
                    break;

                // NOTAS
                // Precisa trocar a ordem la no Sintatico de int e string nos map
                // Está faltando o appearance_qty
                // ainda n sei como vamos controlá-lo
                // Falta appearance_qty
                // check_token_length coloca os valores de length e exceeded_length

                case PARENTHESIS_OPEN:
                    this->word += ch;
                    this->T.lexeme = this->word;
                    this->check_token_length();
                    this->T.token_id = this->find_token(saved_symbols, this->word);
                    this->T.line_appearance.push_back(n_lines);
                    advance(it, this->DASH);
                    this->token_clear();
                    return this->T;
                    break;

                case PARENTHESIS_CLOSE:
                    this->word += ch;
                    this->T.lexeme = this->word;
                    this->check_token_length();
                    this->T.token_id = this->find_token(saved_symbols, this->word);
                    this->T.line_appearance.push_back(n_lines);
                    advance(it, this->DASH);
                    this->token_clear();
                    return this->T;
                    break;

                case PLUS:
                    this->word += ch;
                    this->T.lexeme = this->word;
                    this->check_token_length();
                    this->T.token_id = this->find_token(saved_symbols, this->word);
                    this->T.line_appearance.push_back(n_lines);
                    advance(it, this->DASH);
                    this->token_clear();
                    return this->T;
                    break;

                case HYPHEN:
                    this->word += ch;
                    this->T.lexeme = this->word;
                    this->check_token_length();
                    this->T.token_id = this->find_token(saved_symbols, this->word);
                    this->T.line_appearance.push_back(n_lines);
                    advance(it, this->DASH);
                    this->token_clear();
                    return this->T;
                    break;

                case AMPERSAND:
                    this->word += ch;
                    this->T.lexeme = this->word;
                    this->check_token_length();
                    this->T.token_id = this->find_token(saved_symbols, this->word);
                    this->T.line_appearance.push_back(n_lines);
                    advance(it, this->DASH);
                    this->token_clear();
                    return this->T;
                    break;

                case OLD_LADY_GAME:
                    this->word += ch;
                    this->T.lexeme = this->word;
                    this->check_token_length();
                    this->T.token_id = this->find_token(saved_symbols, this->word);
                    this->T.line_appearance.push_back(n_lines);
                    advance(it, this->DASH);
                    this->token_clear();
                    return this->T;
                    break;

                case LES_THAN:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == LES_EQUAL_THAN;
                    else {
                        this->word += ch;
                        this->T.lexeme = this->word;
                        this->check_token_length();
                        this->T.token_id = this->find_token(saved_symbols, this->word);
                        this->T.line_appearance.push_back(n_lines);
                        advance(it, this->DASH);
                        this->token_clear();
                        return this->T;
                    }
                    
                    break;

                case BIGGER_THAN:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == BIGGER_EQUAL_THAN;
                    else {
                        this->word += ch;
                        this->T.lexeme = this->word;
                        this->check_token_length();
                        this->T.token_id = this->find_token(saved_symbols, this->word);
                        this->T.line_appearance.push_back(n_lines);
                        advance(it, this->DASH);
                        this->token_clear();
                        return this->T;
                    }
                    break;

                case EQUAL:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == EQUAL_EQUAL;
                    else {
                        this->word += ch;
                        this->T.lexeme = this->word;
                        this->check_token_length();
                        this->T.token_id = this->find_token(saved_symbols, this->word);
                        this->T.line_appearance.push_back(n_lines);
                        advance(it, this->DASH);
                        this->token_clear();
                        return this->T;
                    }
                    break;

                case EXCLAMATION:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == EXCLAMATION_EQUAL;
                    else {
                        this->word += ch;
                        this->T.lexeme = this->word;
                        this->check_token_length();
                        this->T.token_id = this->find_token(saved_symbols, this->word);
                        this->T.line_appearance.push_back(n_lines);
                        advance(it, this->DASH);
                        this->token_clear();
                        return this->T;
                    }
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


        char peek(list<char>::iterator& it) {
            list<char>::iterator dupe = it;
            ++dupe;
            return *dupe;
        }

        char find_token(map<string, int>* saved_simbols, string to_find) {
            map<string, int>::iterator it;
            it = saved_symbols.find(to_find);
            if (it != saved_symbols.end()) {
                return (*it).second;
            }
            return 0;
        }

 

    //LesAnalyzer();
    //~LesAnalyzer();
};

