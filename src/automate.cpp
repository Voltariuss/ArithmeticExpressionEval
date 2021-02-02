#include "../include/automate.h"
#include <iostream>

Automate::Automate(const string chain)
{
  this->symbols = new stack<Symbol *>();
  this->states = new stack<State *>();
  this->lexer = new Lexer(chain);

  this->states->push(new State0());
}

Automate::~Automate()
{
  delete (this->symbols);
  delete (this->states);
  delete (this->lexer);
}

void Automate::shift(Symbol *symbol, State *state)
{
  this->symbols->push(symbol);
  this->states->push(state);
  if (!symbol->isTerminal())
  {
    this->lexer->next();
  }
}

void Automate::reduction(int n, Symbol *symbol)
{
  for (int i = 0; i < n; i++)
  {
    State *state = this->states->top();
    this->states->pop();
    delete (state);
  }
  this->states->top()->transition(this, symbol);
}

void Automate::run()
{
  // TODO
}

void Automate::print() const{
  cout << "Automate:" << endl;
  cout << "symbols(top only)=" << endl;
  this->symbols->top()->print();
  cout << "states(top only)=" << endl;
  this->states->top()->print();
  cout << "lexer=" << endl;
  this->lexer->print();
}
