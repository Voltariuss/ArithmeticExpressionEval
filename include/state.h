#pragma once

#include "automate.h"
#include "symbol.h"

using namespace std;

class Automate;
class State
{
public:
  State() {}
  virtual ~State() {}
  virtual bool transition(Automate *automate, Symbol *symbol) const = 0;
  virtual void print() const = 0;
};

class State0 : public State
{
public:
  State0() : State() {}
  ~State0() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};
