# ArithmeticExpressionEval
A basic arithmetic expression evaluation with parser.

## Use
Command syntax: ./main.exe [expression]

BNF notation:
  - \<expression\> ::= \<constant\> | \<expression\> "+" \<expression\> | \<expression\> "*" \<expression\> | "(" \<expression\> ")"
  - \<constant\> ::= [0-9]+

=> Default expression value: (1+34)*123
/!\ no space character allowed /!\
