#include "../include/symbol.h"
#include <iostream>

void Symbol::print() const
{
   cout << "==========" << endl;
   cout << "Symbol id: " << symbolTags[id] << endl;
}

void Number::print() const
{
   Symbol::print();
   cout << "Value: " << value << endl;
}

void Expression::print() const
{
   Symbol::print();
   cout << "Result eval: " << eval() << endl;
}

ExprBinary::~ExprBinary()
{
   delete (operand1);
   delete (operand2);
}

void ExprBinary::print() const
{
   Expression::print();
   cout << "Binary expression" << endl;
}

double ExprPlus::eval() const
{
   return operand1->eval() + operand2->eval();
}

void ExprPlus::print() const
{
   ExprBinary::print();
   cout << "Addition" << endl;
}

double ExprMult::eval() const
{
   return operand1->eval() * operand2->eval();
}

void ExprMult::print() const
{
   ExprBinary::print();
   cout << "Multiplication" << endl;
}
