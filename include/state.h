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

class State1 : public State
{
public:
  State1() : State() {}
  ~State1() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};

class State2 : public State
{
public:
  State2() : State() {}
  ~State2() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};

class State4 : public State
{
public:
  State4() : State() {}
  ~State4() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};

class State5 : public State
{
public:
  State5() : State() {}
  ~State5() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};

class State6 : public State
{
public:
  State6() : State() {}
  ~State6() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};

class State7 : public State
{
public:
  State7() : State() {}
  ~State7() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};

class State8 : public State
{
public:
  State8() : State() {}
  ~State8() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};

class State9 : public State
{
public:
  State9() : State() {}
  ~State9() {}
  bool transition(Automate *automate, Symbol *symbol) const;
  void print() const;
};
