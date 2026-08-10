Arithmetic Expression Calculator

A small, extensible expression parser built with a clean grammar and recursive‑descent design.

Overview
This project implements a minimal arithmetic expression calculator that evaluates numeric expressions and enforces standard mathematical rules using a parenthesis‑driven structure. The architecture follows the open/closed principle, allowing new features to be added gradually without breaking the underlying design.
Current capabilities:
Floating‑point numbers
+ - * /
Parentheses
Unary negation
Correct operator precedence
The goal is to provide a stable foundation for future language features.

Design
The calculator is built from two components:

Tokenizer
Recognizes terminal symbols:
numbers
operators
parentheses
terminators (; or newline)

Parser
Implements a recursive‑descent grammar that enforces precedence and associativity.

Non‑terminal symbols include:
expr_lst
expression
term
factor
This separation keeps the architecture predictable and easy to extend.


