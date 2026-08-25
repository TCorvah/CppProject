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
 * to interpret the input according to the grammar. 
 *
 * @param tokes Mutable lvalue reference to a Tokenizer instance.
 *        Provides the stream of terminal symbols recognized by the
 *        lexer.
 */
    void calculator(Lexer::Tokenizer& tokes);
}//namespace Driver

