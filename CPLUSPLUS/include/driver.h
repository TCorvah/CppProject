#pragma once

#include "lexer.h"
#include <cstdio>


namespace Driver 
{

/**
 * @brief Evaluation driver for expressions produced by the parser.
 *
 * This function consumes terminal symbols produced by the lexer
 * (via the Tokenizer) and invokes the parser's expression routines
 * to interpret the input according to the grammar. After parsing,
 * it evaluates the resulting expression and prints the computed
 * value.
 *
 * @param tokes Mutable lvalue reference to a Tokenizer instance.
 *        Provides the stream of terminal symbols recognized by the
 *        lexer. The driver advances through this stream as it calls
 *        the parser and evaluates expressions.
 */
    void calculator(Lexer::Tokenizer& tokes);
}//namespace Driver

