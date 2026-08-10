#include "lexer.h"
#include "error.h"
#include <cstdio>

using namespace Lexer;

Token Tokenizer::getNextToken() {
    char ch;
    // Pattern match table for operators and punctuation
    static const std::unordered_map<char, TokenType> operator_map {
        { '+', TokenType::plus },
        { '-', TokenType::minus },
        { '*', TokenType::multiply },
        { '/', TokenType::divide },
        { '(', TokenType::leftParen },
        { ')', TokenType::rightParen },
        { ';', TokenType::print }
    };
    while (input_stream.get(ch)) {
        // Terminators: [;\n]
        if (ch == ';' || ch == '\n') {
            return current = { TokenType::print };
        }
        if (isspace(ch)) {
            continue; // Skip whitespace
        }
        // only digits are allowed in numbers, so if we see a non-digit, we can report an error
        // Numbers: [0-9]+(\.[0-9]+)?
        if (isdigit(ch) || ch == '.') {
            input_stream.putback(ch);
            if(input_stream >> current.num_value){
                current.type = TokenType::number;
                return current;
            } else {
                Error::reportError("Invalid number format.");
                input_stream.clear(); // Clear the error state
                input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Skip to the next line
                return current = { TokenType::end }; // Return an end token to continue processing
            }
        }
        // Operators: [+\-*/()]
        if (strchr("+-*/()", ch)) {
            return current = { operator_map.at(ch) };
        }
        Error::reportError("Malformed input.");
        return current = { TokenType::end }; // Return an end token to continue processing
    }
    return current = { TokenType::end };
}


