#pragma once

#include <string>
using namespace std;

enum SymbolId
{
   EXPR,
   OPENPAR,
   CLOSEPAR,
   NUMBER,
   PLUS,
   MULT,
   END,
   ERROR
};

const string symbolTags[] = {"EXPR", "OPENPAR", "CLOSEPAR", "NUMBER", "PLUS", "MULT", "END", "ERROR"};

class Symbol
{
public:
   Symbol(int _id, bool _terminal = true) : id(_id), terminal(_terminal) {}
   virtual ~Symbol() {}
   int getId() const { return id; }
   bool isTerminal() const { return terminal; }
   virtual void print() const;

protected:
   int id;
   bool terminal;
};

class Number : public Symbol
{
public:
   Number(int _value) : Symbol(NUMBER), value(_value) {}
   ~Number() {}
   int getValue() const { return value; }
   void print() const;

protected:
   int value;
};

class Expression : public Symbol
{
public:
   Expression() : Symbol(EXPR, false) {}
   virtual ~Expression() {}
   virtual double eval() const = 0;
   virtual void print() const;
};

class ExprNumber : public Expression
{
public:
   ExprNumber(int _value) : Expression(), value(_value) {}
   ~ExprNumber() {}
   double eval() const;
   void print() const;

protected:
   int value;
};

class ExprBinary : public Expression
{
public:
   ExprBinary(Expression *_operand1, Expression *_operand2) : Expression(), operand1(_operand1), operand2(_operand2) {}
   virtual ~ExprBinary();
   virtual double eval() const = 0;
   virtual void print() const;

protected:
   Expression *operand1;
   Expression *operand2;
};

class ExprPlus : public ExprBinary
{
public:
   ExprPlus(Expression *_operand1, Expression *_operand2) : ExprBinary(_operand1, _operand2) {}
   ~ExprPlus() {}
   double eval() const;
   void print() const;
};

class ExprMult : public ExprBinary
{
public:
   ExprMult(Expression *_operand1, Expression *_operand2) : ExprBinary(_operand1, _operand2) {}
   ~ExprMult() {}
   double eval() const;
   void print() const;
};
