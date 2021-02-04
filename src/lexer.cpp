#include <iostream>
#include "../include/lexer.h"

Symbol *Lexer::read()
{
   if (!this->buffer)
   {
      if (this->head == this->stream.length())
         this->buffer = new Symbol(END);
      else
      {
         switch (this->stream[this->head])
         {
         case '(':
            this->buffer = new Symbol(OPENPAR);
            this->head++;
            break;
         case ')':
            this->buffer = new Symbol(CLOSEPAR);
            this->head++;
            break;
         case '*':
            this->buffer = new Symbol(MULT);
            this->head++;
            break;
         case '+':
            this->buffer = new Symbol(PLUS);
            this->head++;
            break;
         default:
            if (this->stream[this->head] <= '9' && this->stream[this->head] >= '0')
            {
               int result = this->stream[this->head] - '0';
               int i = 1;
               while (this->stream[this->head + i] <= '9' && this->stream[this->head + i] >= '0')
               {
                  result = result * 10 + (this->stream[this->head + i] - '0');
                  i++;
               }
               this->head = this->head + i;
               this->buffer = new Number(result);
            }
            else
            {
               this->buffer = new Symbol(ERROR);
            }
         }
      }
   }
   return this->buffer;
}

void Lexer::next()
{
   this->buffer = nullptr;
}

void Lexer::print() const
{
   cout << "Lexer:" << endl;
   cout << "stream=" << this->stream << endl;
   cout << "head=" << this->head << endl;
   cout << "buffer=" << endl;
   if (this->buffer)
   {
      this->buffer->print();
   }
   else
   {
      cout << "null" << endl;
   }
}
