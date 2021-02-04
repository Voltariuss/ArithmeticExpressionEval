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
  if (symbol->isTerminal())
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

Symbol *Automate::popSymbol()
{
  Symbol *symbol = this->symbols->top();
  this->symbols->pop();
  return symbol;
}

void Automate::popAndDestroySymbol()
{
  Symbol *symbol = this->symbols->top();
  this->symbols->pop();
  delete (symbol);
}

void Automate::run()
{
  bool isAccepted;
  Symbol *symbol;
  do
  {
    symbol = this->lexer->read();
    symbol->print();
    isAccepted = this->states->top()->transition(this, symbol);
    this->print();
  } while (!isAccepted && symbol->getId() != ERROR);

  if (isAccepted)
  {
    Expression *expression = (Expression *)this->symbols->top();
    cout << "================" << endl;
    cout << "     RESULT" << endl;
    cout << "================" << endl;
    cout << this->lexer->getStream() << "=" << expression->eval() << endl;
  }
  else
  {
    cout << "Error during the execution" << endl;
  }
}

void Automate::print() const
{
  cout << "----------" << endl;
  cout << "Automate:" << endl;
  cout << "symbols(top only): size=" << this->symbols->size() << endl;
  if (this->symbols->size() > 0)
  {
    this->symbols->top()->print();
  }
  cout << "states(top only): size=" << this->states->size() << endl;
  this->states->top()->print();
  cout << "lexer=" << endl;
  this->lexer->print();
  cout << endl;
}
