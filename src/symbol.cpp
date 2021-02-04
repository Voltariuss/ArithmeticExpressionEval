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
   cout << "Value=" << this->value << endl;
}

void Expression::print() const
{
   Symbol::print();
   cout << "Expression eval=" << this->eval() << endl;
}

double ExprNumber::eval() const
{
   return this->value;
}

void ExprNumber::print() const
{
   Expression::print();
   cout << "Constant value" << endl;
}

ExprBinary::~ExprBinary()
{
   delete (this->operand1);
   delete (this->operand2);
}

void ExprBinary::print() const
{
   Expression::print();
   cout << "Binary expression" << endl;
}

double ExprPlus::eval() const
{
   return this->operand1->eval() + this->operand2->eval();
}

void ExprPlus::print() const
{
   ExprBinary::print();
   cout << "Addition" << endl;
}

double ExprMult::eval() const
{
   return this->operand1->eval() * this->operand2->eval();
}

void ExprMult::print() const
{
   ExprBinary::print();
   cout << "Multiplication" << endl;
}
