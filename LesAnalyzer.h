#include "Token.h"
#include <map>
#include <string>
#include <iterator>
#include <list>
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
            SLASH, UNDERSCORE, ALPHA_HYPHEN, DIGIT_FLOAT, DIGIT_INT, LES_EQUAL_THAN,
            BIGGER_EQUAL_THAN, EQUAL_EQUAL, EXCLAMATION_EQUAL, SLASH_SLASH, SLASH_ASTERISK
        };

        string word;
        Case state;
        int position;
        int DASH = 1;

        //char current_position;

        Token find_state(list<char>::iterator &it, int &n_lines, map<string, int> saved_symbols, map<string, int> saved_words) {
            char ch;
            this->token_clear();

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
                    char nxt_ch = this->peek(it);

                    // Formação de letra com hífen
                    if (nxt_ch == '-') {
                        this->state = ALPHA_HYPHEN;
                        this->word += ch;
                        advance(it, this->DASH);
                    }

                    else if (!isalnum(nxt_ch)) {
                        // Formação de palavra reservada
                        this->word += ch;
                        advance(it, this->DASH);
                        if (this->find_token(saved_words, this->word) != 0)
                            this->token_save(ch, saved_words, n_lines);
                        else
                            this->token_save(ch, n_lines);
                        return this->T;
                    }

                    // Quebra de linha
                    else if (nxt_ch == '\n') {
                        n_lines++;
                        advance(it, this->DASH);
                    }

                    this->word += ch;
                    advance(it, this->DASH);
                    break;

                case DIGIT:
                    char nxt_ch = this->peek(it);

                    // Formação de float
                    if (nxt_ch == '.') {
                        this->state = DIGIT_FLOAT;
                        this->word += ch;
                        advance(it, this->DASH);
                    }
                    if (!isdigit(nxt_ch) && nxt_ch != '.' && this->state != DIGIT_FLOAT) this->state = DIGIT_INT;
                    if (nxt_ch == '\n') {
                        n_lines++;
                        advance(it, this->DASH);
                    }

                    this->word += ch;
                    advance(it, this->DASH);
                    break;

                // NOTAS
                // Está faltando o appearance_qty
                // ainda n sei como vamos controlá-lo
                // Falta appearance_qty
                // check_token_length coloca os valores de length e exceeded_length
                // Alpha e digit precisam resolver os caracteres invalidos no fim do texto

                case PARENTHESIS_OPEN:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case PARENTHESIS_CLOSE:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case PLUS:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case HYPHEN:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case AMPERSAND:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case OLD_LADY_GAME:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case LES_THAN:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == LES_EQUAL_THAN;
                    else {
                        this->token_save(ch, saved_symbols, n_lines);
                        advance(it, this->DASH);
                        return this->T;
                    }
                    
                    break;

                case BIGGER_THAN:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == BIGGER_EQUAL_THAN;
                    else {
                        this->token_save(ch, saved_symbols, n_lines);
                        advance(it, this->DASH);
                        return this->T;
                    }
                    break;

                case EQUAL:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == EQUAL_EQUAL;
                    else {
                        this->token_save(ch, saved_symbols, n_lines);
                        advance(it, this->DASH);
                        return this->T;
                    }
                    break;

                case EXCLAMATION:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '=') this->state == EXCLAMATION_EQUAL;
                    else {
                        this->token_save(ch, saved_symbols, n_lines);
                        advance(it, this->DASH);
                        return this->T;
                    }
                    break;

                case SEMI_COLON:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case COMMA:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case BRACKETS_OPEN:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case BRACKETS_CLOSE:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case CURLY_BRACKETS_OPEN:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case CURLY_BRACKETS_CLOSED:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case PERCENT:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                
                case ASTERISK:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case PIPE:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case SLASH:
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '/') this->state == SLASH_SLASH;
                    else if (nxt_ch == '*') this->state == SLASH_ASTERISK;
                    else {
                        this->token_save(ch, saved_symbols, n_lines);
                        return this->T;
                    }
                    break;

                case UNDERSCORE:
                    this->token_save(ch, saved_symbols, n_lines);
                    return this->T;
                    break;

                case ALPHA_HYPHEN:
                    this->word += ch;
                    advance(it, this->DASH);
                    this->state = ALPHA;
                    break;

                case DIGIT_FLOAT:
                    char nxt_ch = this->peek(it);
                    if (isdigit(nxt_ch)) {
                        this->word += ch;
                        advance(it, this->DASH);
                    }
                    else {
                        this->word += ch;
                        advance(it, this->DASH);
                        this->token_save('0', n_lines);
                        return this->T;
                    }
                    break;

                case DIGIT_INT:
                    this->token_save(ch, n_lines);
                    return this->T;
                    break;

                case LES_EQUAL_THAN:
                    advance(it, this->DASH);
                    this->token_save(ch, n_lines);
                    return this->T;
                    break;

                case BIGGER_EQUAL_THAN:
                    advance(it, this->DASH);
                    this->token_save(ch, n_lines);
                    return this->T;
                    break;

                case EQUAL_EQUAL:
                    advance(it, this->DASH);
                    this->token_save(ch, n_lines);
                    return this->T;
                    break;

                case EXCLAMATIONS_EQUAL:
                    advance(it, this->DASH);
                    this->token_save(ch, n_lines);
                    return this->T;
                    break;

                case SLASH_SLASH:
                    advance(it, this->DASH);
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '\n') {
                        advance(it, this->DASH);
                        this->state = INITIAL;
                    }
                    else this->state = SLASH_SLASH;
                    break;

                // Se possível melhorar este trecho 
                case SLASH_ASTERISK:
                    advance(it, this->DASH);
                    char nxt_ch = this->peek(it);
                    if (nxt_ch == '*') {
                        advance(it, this->DASH);
                        char nxt_ch = this->peek(it);
                        if (nxt_ch == '/') {
                            advance(it, this->DASH);
                            this->state = INITIAL;
                        }
                        else if (nxt_ch == '\n') {
                            n_lines++;
                            this->state = SLASH_ASTERISK;
                        }
                        else this->state = SLASH_ASTERISK;
                    }
                    else if (nxt_ch == '\n') { 
                        n_lines++;
                        this->state = SLASH_ASTERISK;
                    }
                    else this->state = SLASH_ASTERISK;
                    break;

                default:
                    break;
                }

            }
        
        }

    private:

        void token_save(char ch, map<string, int> saved_symbols, int n) {
            this->word += ch;
            this->T.lexeme = this->word;
            this->check_token_length();
            this->T.token_id = this->find_token(saved_symbols, this->word);
            this->T.line_appearance.push_back(n);
        }

        void token_save(char ch, int n) {
            this->word += ch;
            this->T.lexeme = this->word;
            this->check_token_length();
            // Token id para um nome de variável
            this->T.token_id = 0;
            this->T.line_appearance.push_back(n);
        }

        void token_clear() {
            this->word.clear();

            this->T.token_id = 0;
            //this->T.length = 0;
            //this->T.exceeded_length = 0;
            this->T.lexeme.clear();
            this->T.appearance_qty = 0;
            this->T.line_appearance.clear();
            this->T.ch = ' ';
            this->state = INITIAL;
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

        int find_token(map<string, int> saved_symbols, string to_find) {
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

