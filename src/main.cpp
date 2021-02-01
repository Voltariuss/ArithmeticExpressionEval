#include <iostream>
#include "../include/lexer.h"

int main(void)
{
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Symbol *s;
   while ((s = l.read())->getId() != END)
   {
      s->print();
      l.next();
   }
   return 0;
}
