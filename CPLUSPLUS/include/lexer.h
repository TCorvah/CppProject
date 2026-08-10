#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <string>
#include <cctype>
#include <cstdio>

namespace Lexer {
    enum class TokenType : char {
        number,
        end,
        plus = '+',
        minus = '-',
        multiply = '*',
        divide = '/',
        print = ';',
        assign = '=',
        leftParen = '(',
       rightParen = ')',

    };

    struct Token {
        TokenType type;
        double num_value; // Only used if type is number
        std::string str_value; // may be extended later
    };

    class Tokenizer {
    public:
        Tokenizer(std::istream& input) : input_stream(input) {}
        ~Tokenizer() = default;
        Token getNextToken(); //read and return next token
        const Token& currentToken(){ // most recently read token
            return current;
        };

    private:
        std::istream& input_stream;
        Token current {TokenType::end};
    };

    //extern Tokenizer tokenizer;
}//namespace Lexer




