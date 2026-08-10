#include "driver.h"
#include "lexer.h"
#include "error.h"

#include <iostream>
#include <string>
#include <cstdio>

int main()
{
   std::cout << "Welcome to the calculator. Enter expressions to evaluate or an empty line to exit.\n";
   std::string input;
   while(std::cout << ">> " && std::getline(std::cin, input)) {
       if (input == " " || input.empty()) {
           break;         
       }
       std::istringstream input_stream(input);
       Lexer::Tokenizer tokenizer(input_stream);
       Driver::calculator(tokenizer);
   }
   return Error::errorCount;
}
