#pragma once

#include <stack>
#include <string>
#include "symbol.h"
#include "state.h"
#include "lexer.h"

using namespace std;

class State;
class Automate
{
public:
  Automate(const string chain);
  ~Automate();
  void shift(Symbol *symbol, State *e);
  void reduction(int n, Symbol *symbol);
  Symbol *popSymbol();
  void popAndDestroySymbol();
  void run();
  void print() const;

protected:
  stack<Symbol *> *symbols;
  stack<State *> *states;
  Lexer *lexer;
};