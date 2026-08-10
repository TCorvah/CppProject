#include "parser.h"
#include "error.h"
#include <cstdio>

using namespace Parser;

double ParserSyntax::parseExpression(bool getNextToken) {
    double left = parseTerm(getNextToken);
    for (;;) {
        switch (token.currentToken().type) {
        case TokenType::plus:
            left += parseTerm(true);
            break;
        case TokenType::minus:
            left -= parseTerm(true);
            break;
        default:
            return left;
        }
    }
}

double ParserSyntax::parseTerm(bool getNextToken) {
    double left = parseFactor(getNextToken);
    for (;;) {
        switch (token.currentToken().type) {
        case TokenType::multiply:
            left *= parseFactor(true);
            break;
        case TokenType::divide:
            if (auto token = parseFactor(true)){
                left /= token;
                break;
            } 
            return Error::reportError("Division by zero.");           
        default:
            return left;
        }
    }
}

double ParserSyntax::parseFactor(bool getNextToken){
    if (getNextToken) {
        token.getNextToken();
    }
    switch (token.currentToken().type) {
    case TokenType::number:{
         double value = token.currentToken().num_value;
         token.getNextToken();
         return value; // Move to the next token after consuming the number
    }
    case TokenType::minus:
        return -parseFactor(true);
    case TokenType::leftParen: {
        auto expression = parseExpression(true);
        if (token.currentToken().type != TokenType::rightParen) {
            return Error::reportError("Missing ')' "); // Report error for missing ')'
            token.getNextToken(); // Attempt to recover by moving to the next token
            return expression; // Return the parsed expression even if ')' is missing
        }
    }
    default:
       return Error::reportError("factor expected");
    }
}
