#pragma once

#include <string>
using namespace std;

enum SymbolId
{
   EXPR,
   OPENPAR,
   CLOSEPAR,
   PLUS,
   MULT,
   INT,
   END,
   ERROR
};

const string symbolTags[] = {"EXPR", "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "END", "ERROR"};

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
   Number(int _value) : Symbol(INT), value(_value) {}
   ~Number() {}
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
