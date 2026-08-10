#include "driver.h"
#include "parser.h"
#include <string>
#include <iostream>
#include <cstdio>

using namespace Driver;
    void Driver::calculator(Lexer::Tokenizer& tokes) {  
        Parser::ParserSyntax parser(tokes);  
        tokes.getNextToken();
        for (;;) {
            auto token = tokes.currentToken().type;
            if(token == Lexer::TokenType::end || token == Lexer::TokenType::print) {
                break;
            }
            //if(tokes.currentToken().type == Lexer::TokenType::print){
            //    continue;   // skip empty lines or stray semicolons
            //}
            std::cout << parser.parseExpression(false) << '\n';     
        }
   }