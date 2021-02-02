#include <iostream>
#include "../include/lexer.h"

Symbol *Lexer::read()
{
   if (!buffer)
   {
      if (head == stream.length())
         buffer = new Symbol(END);
      else
      {
         switch (stream[head])
         {
         case '(':
            buffer = new Symbol(OPENPAR);
            head++;
            break;
         case ')':
            buffer = new Symbol(CLOSEPAR);
            head++;
            break;
         case '*':
            buffer = new Symbol(MULT);
            head++;
            break;
         case '+':
            buffer = new Symbol(PLUS);
            head++;
            break;
         default:
            if (stream[head] <= '9' && stream[head] >= '0')
            {
               int result = stream[head] - '0';
               int i = 1;
               while (stream[head + i] <= '9' && stream[head + i] >= '0')
               {
                  result = result * 10 + (stream[head + i] - '0');
                  i++;
               }
               head = head + i;
               buffer = new Number(result);
            }
            else
            {
               buffer = new Symbol(ERROR);
            }
         }
      }
   }
   return buffer;
}

void Lexer::next()
{
   buffer = nullptr;
}

void Lexer::print() const
{
   cout << "Lexer:" << endl;
   cout << "stream=" << stream << endl;
   cout << "head=" << head << endl;
   cout << "buffer=" << endl;
   this->buffer->print();
}
