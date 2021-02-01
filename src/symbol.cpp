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

ExprBinary::~ExprBinary() {
   delete(operand1);
   delete(operand2);
}

void ExprBinary::print() const {
   Expression::print();
   cout << "Binary expression" << endl;
}
