#pragma once

#include "lexer.h"

// The Parser  class does the syntatic analysis of the input expression. 
//It uses the Tokenizer to get tokens and evaluates the expression based on the defined grammar rules.
namespace Parser{
    using namespace Lexer;
    class ParserSyntax{
    public:
        ParserSyntax(Tokenizer& tokenizer) : token(tokenizer) {}
        double parseExpression(bool);
        double parseTerm(bool);
        double parseFactor(bool);

    private:
        Tokenizer& token;
    };
    
}//namespace Parser