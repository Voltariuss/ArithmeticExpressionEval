#include <iostream>
#include "../include/state.h"
#include "../include/symbol.h"

bool State0::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case OPENPAR: {
      automate->shift(symbol, new State2());
      break;
    }
    case EXPR: {
      automate->shift(symbol, new State1());
      break;
    }
  }
  return false;
}

void State0::print() const {
  cout << "State0" << endl;
}

bool State1::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case PLUS: {
      automate->shift(symbol, new State4());
      break;
    }
    case MULT: {
      automate->shift(symbol, new State5());
      break;
    }
    case END: {
      return true;
      break;
    }
  }
  return false;
}

void State1::print() const {
  cout << "State1" << endl;
}

bool State2::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case OPENPAR: {
      automate->shift(symbol, new State2());
      break;
    }
    case EXPR: {
      automate->shift(symbol, new State6());
    }
  }
  return false;
}

void State2::print() const {
  cout << "State2" << endl;
}

bool State4::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case OPENPAR: {
      automate->shift(symbol, new State2());
      break;
    }
    case EXPR: {
      automate->shift(symbol, new State7());
      break;
    }
  }
  return false;
}

void State4::print() const {
  cout << "State4" << endl;
}

bool State5::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case OPENPAR: {
      automate->shift(symbol, new State2());
      break;
    }
    case EXPR: {
      automate->shift(symbol, new State8());
      break;
    }
  }
  return false;
}

void State5::print() const {
  cout << "State5" << endl;
}

bool State6::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case PLUS: {
      automate->shift(symbol, new State4());
      break;
    }
    case MULT: {
      automate->shift(symbol, new State5());
      break;
    }
    case CLOSEPAR: {
      automate->shift(symbol, new State9());
      break;
    }
  }
  return false;
}

void State6::print() const {
  cout << "State6" << endl;
}

bool State7::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case MULT: {
      automate->shift(symbol, new State5());
      break;
    }
    case PLUS: {}
    case CLOSEPAR: {}
    case END: {
      Expression *operand1 = (Expression *) automate->popSymbol();
      automate->popAndDestroySymbol();
      Expression *operand2 = (Expression *) automate->popSymbol();
      automate->reduction(3, new ExprPlus(operand1, operand2));
      break;
    }
  }
  return false;
}

void State7::print() const {
  cout << "State7" << endl;
}

bool State8::transition(Automate *automate, Symbol *symbol) const
{
  switch (symbol->getId()) {
    case PLUS: {}
    case MULT: {}
    case CLOSEPAR: {}
    case END: {
      Expression *operand1 = (Expression *) automate->popSymbol();
      automate->popAndDestroySymbol();
      Expression *operand2 = (Expression *) automate->popSymbol();
      automate->reduction(3, new ExprMult(operand1, operand2));
      break;
    }
  }
  return false;
}

void State8::print() const {
  cout << "State8" << endl;
}

bool State9::transition(Automate *automate, Symbol *symbol) const
{
  // TODO
  return false;
}

void State9::print() const {
  cout << "State9" << endl;
}
