#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <string>
#include <cctype>
#include <cstdio>

/**
 * @brief Lexical analysis components for tokenizing input.
 *
 * The Lexer namespace defines the TokenType enum of char, the Token
 * struct that maps each TokenType with its associated value, and the Tokenizer class which converts
 *  character input into a stream of tokens for the parser.
 * 
 */
namespace Lexer {

    /**
     * @brief Enumerates all terminal symbols recognized by the lexer.
     *
     * Includes single-character operators, punctuation, and parentheses.
     * Numeric literals are represented by TokenType::number and carry
     * their floating-point value in the Token structure.
    */
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

    /**
     * @brief Represents a single lexical token.
     *
     * Each Token stores a TokenType and its associated value. For
     * TokenType::number, the value is stored in num_value. Other token
     * types may use str_value for future extensions such as identifiers.
     */
    struct Token {
        TokenType type;
        double num_value; 
        std::string str_value; 
    };

    /**
     * @brief Converts character input into a stream of tokens.
     *
     * The Tokenizer reads characters from an input stream, groups digits
     * into numeric literals, recognizes single-character operators, and
     * produces Token objects. currentToken() returns the most recently
     * read token.
     */
    class Tokenizer {
    public:
        Tokenizer(std::istream& input) : input_stream(input) {}
        ~Tokenizer() = default;
        Token getNextToken(); 
        const Token& currentToken(){
            return current;
        };

    private:
        std::istream& input_stream;
        Token current {TokenType::end};
    };

    //extern Tokenizer tokenizer;
}//namespace Lexer




