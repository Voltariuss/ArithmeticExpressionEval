#pragma once

#include <string>
#include "symbol.h"
using namespace std;

class Lexer
{
public:
   Lexer(string _stream) : stream(_stream), head(0), buffer(nullptr) {}
   ~Lexer() {}
   Symbol *read();
   void next();
   string getStream() const { return this->stream; }
   void print() const;

protected:
   string stream;
   int head;
   Symbol *buffer;
};
