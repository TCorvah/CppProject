#pragma once

#include "lexer.h"
/**
 * @brief Syntax analysis components that parse the non‑terminal symbols
 *        of the grammar production rules.
 *
 * The Parser namespace builds on the Lexer namespace by consuming the
 * token stream produced by the Tokenizer. Each token represents a
 * terminal symbol in the grammar, and the parser evaluates expressions
 * according to the defined grammar rules.
 *
 * The parser implements a top‑down, recursive‑descent strategy: each
 * parsing function corresponds to a non‑terminal in the grammar and
 * enforces the structure of that production rule. The Tokenizer is
 * provided as input, and the parser advances through the token stream
 * while validating syntactic correctness.
 */
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